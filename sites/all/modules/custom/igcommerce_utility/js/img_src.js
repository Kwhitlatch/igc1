// Apply default missing image
function applyDefaultImg(source) {
  var default_img = Drupal.settings.ig_default_img;
  var c = source.parentNode.childNodes;
  source.onerror = '';
  source.setAttribute('data-original-src', source.src);
  source.src = default_img;

  for(var i=0;i<c.length;i++) {
    c[i].srcset = default_img;
  };  
}