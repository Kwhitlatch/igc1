var gulp = require('gulp');
var sass = require('gulp-sass');
var inject = require('gulp-inject');
var wiredep = require('wiredep').stream;
var notify = require("gulp-notify");
var browserSync = require('browser-sync');
var htmlmin = require('gulp-htmlmin');
var inlinesource = require('gulp-inline-source');
var uncss = require('gulp-uncss');
var sourcemaps = require('gulp-sourcemaps');
const autoprefixer = require('gulp-autoprefixer');
var del = require('del');
var cssmin = require('gulp-cssmin');
var rename = require("gulp-rename");

gulp.task('styles', function(){
  var injectAppFiles = gulp.src('src/styles/*.scss', {read: false});
  var injectGlobalFiles = gulp.src('src/global/*.scss', {read: false});

  function transformFilepath(filepath) {
    return '@import "' + filepath + '";';
  }

  var injectAppOptions = {
    transform: transformFilepath,
    starttag: '// inject:app',
    endtag: '// endinject',
    addRootSlash: false
  };

  var injectGlobalOptions = {
    transform: transformFilepath,
    starttag: '// inject:global',
    endtag: '// endinject',
    addRootSlash: false
  };

  return gulp.src('src/brand-chooser.scss')
  .pipe(sourcemaps.init())
    .pipe(wiredep())
    .pipe(inject(injectGlobalFiles, injectGlobalOptions))
    .pipe(inject(injectAppFiles, injectAppOptions))
    .pipe(sass())
    .pipe(uncss({
            html: ['src/*.html'],
            ignore : [  // These support basic bootstrap functions
                        /\.affix/,
                        // /\.alert/,
                        /\.close/,
                        /\.collapse/,
                        /\.fade/,
                        /\.has/,
                        // /\.help/,
                        /\.in/,
                        /\.modal/,
                        /\.open/,
                        // /\.popover/,
                        // /\.tooltip/,
                        // These support tab-collapse.js
                        /\.visible-xs/,
                        /\.hidden-xs/,
                        /.panel.*/
                        ],
            }))
    .pipe(autoprefixer('last 5 versions', 'ie >= 8'))
    .pipe(cssmin())
    .pipe(rename({suffix: '.min'}))
    // When inline injection is turned on, you'll want to switch this back on
    // Google page speed insights flags sourcemaps as "unminified css" so these should not make it to production
    //.pipe(sourcemaps.write())
    //.pipe(gulp.dest('src/compiled-css'));
     .pipe(gulp.dest('dist/styles'));
});

gulp.task('html', ['styles', 'copy-images', 'copy-javascript'], function(){
 
  return gulp.src('src/brands.html')
   
    
    //This minifies html output. 
    .pipe(htmlmin({
      collapseWhitespace: true,
      minifyCSS: true,
      minifyJS: true,
      removeComments: true,
      //useShortDoctype: true
    }))
     // This inlines the css
    .pipe(inlinesource())
    .pipe(gulp.dest('dist'))
    .pipe(notify({
      title: "SASS Compiled",
      message: "All SASS files have been recompiled to CSS and you are a rockstar!.",
      sound: 'Submarine',
      onLast: true
    }))
});

gulp.task('html-watch', ['html'], browserSync.reload);
gulp.task('sass-watch', ['styles'], browserSync.reload);

gulp.task('default', function () {
  browserSync({
      server: {
        baseDir: 'dist/'
      }
  });
  gulp.watch('src/styles/*.scss', ['sass-watch']);
  gulp.watch('src/*.html', ['html-watch']);
});

//copies and optimizes images from sourc to dist
gulp.task('copy-images', function () {
    gulp.src('src/assets/images/*')
        .pipe(gulp.dest('dist/images'));
});

//copies favicons from sourc to dist
// When this was converted to a Drupal module and moved to IGCommerce, we pointed
// the favicon urls to the Base installation, so this was no longer needed.
// gulp.task('copy-favicons', function () {
//     gulp.src('src/assets/favicons/*')
//         .pipe(gulp.dest('dist'));
// });


//copies js from sourc to dist
gulp.task('copy-javascript', function () {
    gulp.src('src/assets/javascript/*')
      .pipe(gulp.dest('dist/js'));
});
// Rather than optimize programtically, I'm more familiar with imagemagick and  found it easier to use imagemagick and
// the command line. If image magic is installed, you can execute this from terminal:
// convert Fluke-brand-choser-page-1440x500.jpg -sampling-factor 4:2:0 -strip -quality 85 -interlace JPEG -colorspace sRGB ../images/Fluke-brand-choser-page-1440x500.jpg
// This is inline with googles recomendations here: https://developers.google.com/speed/docs/insights/OptimizeImages

//deletes everything in the dist folder before rebuilding
gulp.task('clean', function(cb){
  del(['dist'], cb);
});