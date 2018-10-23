<?php if(!empty($items)): ?>
    <div class="custom-collapse">
        <button class="btn btn-block collapse-toggle visible-xs visible-sm" type="button" data-toggle="collapse"
                data-parent="custom-collapse" data-target="#accordion-left" aria-expanded="false">
            <span class=""><?php print t('Choose your category'); ?></span>
            <span class="pull-right fluke-icon fluke-icon-fa-bars">
      </span>
        </button>
        <div class="panel-group collapse in" id="accordion-left" aria-expanded="true" role="menu">
            <?php foreach ($items as $level2): ?>
            <!-- If a parent item is marked as hide from left nav(1), it won't populate item. If it is blank OR (0), it will-->
            <?php if (strpos($level2['hide'], '1') === false): ?>
                <div class="panel panel-default">
                    <div class="panel-heading  <?php print $level2['expand_wrapper']; ?>">
                        <h4 class="panel-title">
                            <?php
                                print l($level2['name'], $level2['link'], array(
                                        'html' => TRUE,
                                        'language' => $language,
                                        'attributes' => array(
                                            'target'=>($level2['destination'] == 'external') ? '_blank': '',
                                            'class'=> [$level2['class'], $level2['active_trail_indicator']]))
                                )
                            ; ?>
                        </h4>
                        <?php if(isset($level2['show_children']) && $level2['show_children'] && count($level2['children']) > 1): ?>
                            <a data-toggle="collapse" class="collapsed plus-minus pull-right <?php print $level2['expand']; ?>" data-parent="#accordion-left"
                               href="#collapse-<?php print $level2['id']; ?>"></a>
                        <?php endif; ?>
                    </div>
                    <?php if(isset($level2['show_children']) && $level2['show_children']): ?>
                        <div id="collapse-<?php print $level2['id']; ?>" class="panel-collapse collapse" style="display: <?php print $level2['display']; ?>" role="menuitem">
                            <div class="panel-body">
                                <?php foreach($level2['children'] as $level3): ?>
                                <!-- If a Child item is marked as hide from left nav(1), it won't populate item. If it is blank OR (0), it will-->
                                <?php if (strpos($level3['hide'], '1') === false): ?>
                                    <div class="child-menu-item">
                                        <?php
                                            print l($level3['name'], $level3['link'], array(
                                                    'html' => TRUE,
                                                    'language' => $language,
                                                    'attributes' => array(
                                                        'target'=>($level3['destination'] == 'external') ? '_blank': '',
                                                        'class'=> [$level3['class'], $level3['active_trail_indicator']]))
                                                )
                                        ; ?>
                                    </div>
                                <?php endif; ?> <!--End Parent hide from left nav-->
                                <?php endforeach; ?>
                            </div>
                        </div>
                    <?php endif; ?>
                </div>
            <?php endif; ?> <!--End Parent hide from left nav-->
            <?php endforeach; ?>
        </div>
    </div>
<?php endif; ?>
