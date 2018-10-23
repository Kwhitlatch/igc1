<?php if(!empty($items) && is_object($items['details'])): ?>
    <?php //dpm($items); ?>
    <div class="panel panel-default">
        <div class="panel-heading" id="fluke-product-display-apps-title" role="tab">
            <h4 class="panel-title">
                <a aria-controls="fluke-product-display-apps-list" aria-expanded="false" class="collapsed"  href="#fluke-product-display-apps-list" role="button">
                    <?php print t($items['accet_name']); ?> ( <?php print $items['total']; ?> )
                </a></h4>
        </div><!-- end .panel-heading-->
        <div aria-labelledby="fluke-product-display-apps-title" class="panel-collapse collapse" id="fluke-product-display-apps-list" role="tabpanel">
            <div class="panel-body">
                <ul class="fluke-product-display-apps-list">
                    <?php foreach ($items['details'] as $item): ?>
                        <li class="fluke-product-display-apps-item">
                            <a href="<?php print $item->url; ?>">
                                <?php print $item->al; ?>
                            </a>
                        </li>
                    <?php endforeach; ?>
                </ul>
            </div><!-- end .panel-body-->
        </div><!-- end .panel-collapse-->
    </div><!-- end .panel-->
<?php endif; ?>