var gulp = require('gulp');
var gutil = require('gulp-util');
var sass = require('gulp-sass');
var watch = require('gulp-watch');
var shell = require('gulp-shell');
var notify = require('gulp-notify');
var sourcemaps = require('gulp-sourcemaps');
var uglify = require('gulp-uglify');
var fs = require("fs");
var sassGlob = require('gulp-sass-glob');
var plumber = require("gulp-plumber");
var importer = require('node-sass-globbing');
var config = require("./config");
var livereload = require('gulp-livereload');

/**
 * If config.js exists, load that config for overriding certain values below.
 */
function loadConfig() {
  if (fs.existsSync(__dirname + "/./config.js")) {
    config = {};
    config = require("./config");
  }

  return config;
}

loadConfig();

/**
 * This task generates CSS from all SCSS files and compresses them down.
 * sourcemaps are added here too.
 */
gulp.task('sass-map', function () {
  return gulp.src('./scss/**/*.scss')
      .pipe(plumber())
      .pipe(sassGlob())
      .pipe(sourcemaps.init())
    .pipe(sass({
      importer: importer,
      noCache: true,
      outputStyle: "extended",
      lineNumbers: false,
      loadPath: './css/*',
      sourceMap: true
    })).on('error', function(error) {
      gutil.log(error);
      this.emit('end');
    })
    .pipe(sourcemaps.write('./maps'))
    .pipe(gulp.dest('./css'))
    .pipe(notify({
      title: "SASS Compiled",
      message: "All SASS files have been recompiled to CSS and you are a rockstar!.",
      onLast: true
    }))
    .pipe(livereload())
});

/**
 * This task generates CSS from all SCSS files and compresses them down.
 * This version does not have sourcemaps - it is required for production.
 */
gulp.task('sass', function () {
  return gulp.src('./scss/**/*.scss')
      .pipe(plumber())
      .pipe(sassGlob())
      //.pipe(sourcemaps.init())
    .pipe(sass({
      importer: importer,
      noCache: true,
      outputStyle: "extended",
      lineNumbers: false,
      loadPath: './css/*',
      //sourceMap: true
    })).on('error', function(error) {
      gutil.log(error);
      this.emit('end');
    })
    //.pipe(sourcemaps.write('./maps'))
    .pipe(gulp.dest('./css'))
    .pipe(notify({
      title: "SASS Compiled",
      message: "All SASS files have been recompiled to CSS sans sourcemaps. This is production ready.",
      onLast: true
    }))
    .pipe(livereload())
});

/**
 * This task minifies javascript in the js/js-src folder and places them in the js directory.
 */
gulp.task('compress', function() {
  return gulp.src('./js/js-src/*.js')
    .pipe(sourcemaps.init())
    .pipe(uglify())
    .pipe(sourcemaps.write('./maps'))
    .pipe(gulp.dest('./js'))
    .pipe(notify({
      title: "JS Minified",
      message: "All JS files in the theme have been minified.",
      onLast: true
    }));
});

/**
 * Defines a task that triggers a Drush cache clear.
 */
gulp.task('drush:cc', function () {
  if (config !== null && !config.drush.enabled) {
    return;
  }

  return gulp.src('', {read: false})
    .pipe(shell([
      config.drush.alias.css_js
    ]))
    .pipe(notify({
      title: "Caches cleared",
      message: "Drupal CSS/JS caches cleared.",
      onLast: true
    }));
});

/**
 * Defines a task that triggers a Drush cache rebuild.
 */
gulp.task('drush:cr', function () {
  if (!config.drush.enabled) {
    return;
  }

  return gulp.src('', {read: false})
    .pipe(shell([
      config.drush.alias.cr
    ]))
    .pipe(notify({
      title: "Cache rebuilt",
      message: "Drupal cache rebuilt.",
      onLast: true
    }));
});


/**
 * Defines the watcher task.
 */
gulp.task('watch', function() {
  // watch for changes, reload page on change  
  livereload.listen();
  // watch scss for changes and clear drupal theme cache on change
  gulp.watch(['scss/**/*.scss'], ['sass', 'drush:cc']);

  // watch js for changes and clear drupal theme cache on change
  gulp.watch(['js-src/**/*.js'], ['compress', 'drush:cc']);
});

gulp.task('default', ['watch']);