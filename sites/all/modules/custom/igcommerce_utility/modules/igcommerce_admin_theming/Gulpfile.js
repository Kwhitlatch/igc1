var gulp = require('gulp');
var sass = require('gulp-sass');
var sourcemaps = require('gulp-sourcemaps');
var sassGlob = require('gulp-sass-glob');
var plumber = require('gulp-plumber');
var livereload = require('gulp-livereload');
var autoprefixer = require('gulp-autoprefixer');

gulp.task('sass', function() {
  gulp.src('sass/**/*.scss')
  .pipe(sassGlob())
  .pipe(plumber())
  .pipe(sourcemaps.init())
  //.pipe(sass().on('error', sass.logError))
  .pipe(sass({outputStyle: 'compressed'}).on('error', sass.logError))
  .pipe(autoprefixer())
  .pipe(sourcemaps.write('../maps'))
  .pipe(gulp.dest('./css/'))
  .pipe(livereload());
  });

//Watch task
gulp.task('default',function() {
  livereload.listen();
  gulp.watch('sass/**/*.scss',['sass']);
  });