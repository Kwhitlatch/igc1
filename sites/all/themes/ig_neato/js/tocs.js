!function(i){"use strict";Drupal.behaviors.igcommerce_tocs={attach:function(e,t){i("h3.slider-trigger").once("myslider",function(){i("h3.slider-trigger").click(function(){i(".slider").slideToggle()})});"undefined"!=typeof console&&console.log("Module loaded file"),i(".quicktabs-tabpage",e).each(function(){var e=10;i(this).find(".row:lt("+e+")").show(),i(this).find("#showLess").hide();var t=i(this).find(".row").size();if("undefined"!=typeof console){var s=i(this).attr("id");console.log("Div "+s+" has ("+t+") total items")}t<=9&&(i(this).find("#loadMore").hide(),i(this).find(".total_loaded").text(t)),t>1&&(i(this).find(".number_of_items").css("display","inline-block"),i(this).find(".total_items").text(t)),t>=10&&(i(this).find("#loadMore").css("display","inline-block"),i(this).find(".total_loaded").text(e)),i(this).children().find("#loadMore").once().on({click:function(){"undefined"!=typeof console&&console.log("LoadMore clicked");var s=i(this);t=s.parents(".quicktabs-tabpage").find(".row").size(),e=s.parents(".quicktabs-tabpage").find(".row:visible").size()+10,s.parents(".quicktabs-tabpage").find(".total_loaded").empty().text(e);var a=s.parents(".quicktabs-tabpage").find(".row:hidden").size();a<10&&(s.parents(".quicktabs-tabpage").find(".total_loaded").empty().text(t),s.parents(".quicktabs-tabpage").find("#showLess").css("display","inline-block")),e>=t&&s.parents(".quicktabs-tabpage").find("#showLess").css("display","inline-block"),e<t?s.parents(".quicktabs-tabpage").find(".row:lt("+e+")").slideDown("fast",function(){var i=s.parents(".quicktabs-tabpage").find(".row:visible").size();s.parents(".quicktabs-tabpage").find("#showLess").css("display","inline-block"),i>=t&&s.hide()}):(s.parents(".quicktabs-tabpage").find(".row:lt("+t+")").slideDown("fast"),s.hide())}}),i(this).children().find("#showLess").once().on({click:function(){"undefined"!=typeof console&&console.log("Showless clicked");var s=i(this);if(t=s.parents(".quicktabs-tabpage").find(".row:visible").size(),t>10){var a=t/10;a%1==0?(t=t-10<0?e:t-10,s.parents(".quicktabs-tabpage").find(".row").not(":lt("+t+")").slideUp(1e3,function(){t=s.parents(".quicktabs-tabpage").find(".row:visible").size(),i(this).parents(".quicktabs-tabpage").find(".total_loaded").empty().text(t),s.parents(".quicktabs-tabpage").find(".row:visible").size()<=10&&s.hide()})):(t=a.toString().split(".")[1],s.parents(".quicktabs-tabpage").find(".row:visible").slice(-t).slideUp(1e3,function(){t=s.parents(".quicktabs-tabpage").find(".row:visible").size(),s.parents(".quicktabs-tabpage").find(".total_loaded").empty().text(t)}))}s.parents(".quicktabs-tabpage").find("#loadMore").css("display","inline-block")}})})}}}(jQuery);
//# sourceMappingURL=maps/tocs.js.map
