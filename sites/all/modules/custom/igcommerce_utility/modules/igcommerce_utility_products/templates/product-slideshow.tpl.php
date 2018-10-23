
<div class="ig-product-flexslider" id="ig-product-flexslider">
    <ul class="slides">

    <?php foreach ($content as $val): ?>
        <?php if (!empty($val['url'])) : ?>
            <?php
            $image_url = '';
            $val = igcommerce_utility_slideshow_image_helper($val, $image_url);
            ?>
            <li data-thumb="<?php print $val['thumb']; ?>" class="zoom" itemprop="image"><?php print $image_url; ?></li>

        <?php elseif ((!empty($val['url']) && strpos( $val['url'], 'brightcove'))): ?>
            <?php $vid = explode('=', $val['url'])[1]; ?>
           <li data-thumb="<?php print (!empty($val['thumbnail']) ? $val['thumbnail'] : 'http://f1.media.brightcove.com/8/5229431846001/5229431846001_5398442553001_'.$vid.'-vs.jpg?pubId=5229431846001&videoId='.$vid); ?>">
               <div style="display: block; position: relative; max-width: 100%;">
                   <div style="padding-top: 56.25%;">
                       <iframe src="<?php print $val['url']; ?>" style="width: 100%; height: 100%; position: absolute; top: 0px; bottom: 0px; right: 0px; left: 0px;" itemprop="image" allowfullscreen></iframe>
                   </div>
               </div>
           </li>
        <?php elseif ((!empty($val['url']) && strpos( $val['url'], 'youtube'))): ?>
           <li data-thumb="<?php print (isset($val['thumbnail']) ? $val['thumbnail'] : $val['url']); ?>">
                <div style="display: block; position: relative; max-width: 100%;">
                    <div style="padding-top: 56.25%;">
                        <iframe src="<?php print $val['url']; ?>" style="width: 100%; height: 100%; position: absolute; top: 0px; bottom: 0px; right: 0px; left: 0px;" itemprop="image" allowfullscreen></iframe>
                    </div>
                </div>
            </li>
        <?php endif; ?>

    <?php endforeach; ?>
    </ul>
</div>