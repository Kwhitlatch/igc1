<?php if(!empty($items)): ?>
    <ul class="nav navbar-nav" id="<?php print $language->language; ?>-nav">
        <?php foreach($items as $level1): ?>
            <?php if($level1['destination'] == 'external'): ?>
            <li class="dropdown top-lvl-<?php print $level1['en_us_url']; ?>">
                <?php print l($level1['name'], $level1['link'],
                    array('html' => TRUE,
                        'language' => $language,
                        'attributes' => array(
                            'class' => ['dropdown-toggle'],
                            'data-toggle' => 'dropdown',
                            'role' => 'button',
                            'aria-expanded' => 'false',
                            'aria-haspopup' => 'true')
                        )
                    );
                ?>
            <?php else: ?>
            <li class="dropdown top-lvl-<?php print $level1['en_us_url']; ?>">
                <?php print l($level1['name'], $level1['link'],
                    array('html' => TRUE,
                        'language' => $language,
                        'attributes' => array(
                        'class' => ['dropdown-toggle', $level1['active_trail_indicator']],
                        'data-toggle' => 'dropdown',
                        'role' => 'button',
                        'aria-expanded' => 'false',
                        'aria-haspopup' => 'true')
                    )
                );
                ?>
            <?php endif; ?>
                <?php if(isset($level1['show_children']) && $level1['show_children']): ?>
                    <ul class="dropdown-menu">
                        <li class="<?php print $level1['class']; ?> <?php print $level1['active_trail_indicator']; ?>">
                            <ul>
                            <?php foreach($level1['children'] as $level2): ?>
                                        <?php if($level1['en_us_url'] == "products"): ?>
                                            <?php if(isset($column_splitter) && is_array($column_splitter) && in_array($level2['en_us_url'], $column_splitter)): ?>
                                                </ul></li>
                                                <li class="nav-column col-md-5ths"><ul>
                                            <?php endif; ?>
                                        <?php endif; ?>
                                        <li class="second-lvl second-lvl-<?php print $level2['en_us_url']; ?> <?php print $level2['class']; ?> <?php print $level2['active_trail_indicator']; ?>">
                                            <?php $class = 'event-nav-' . drupal_html_class($level2['en_us_name']); ?>
                                            <?php print l($level2['name'], $level2['link'], array('language' => $language, 'attributes' => array('class' => array($class)))) ; ?>
                                            <?php if(isset($level2['show_children']) && !empty($level2['children'])): ?>
                                                <ul>
                                                <?php foreach($level2['children'] as $level3): ?>
                                                    <li class="<?php print $level3['active_trail_indicator']; ?>">
                                                        <?php $class = 'event-nav-' . drupal_html_class($level2['en_us_name']); ?>
                                                        <?php print l($level3['name'], $level3['link'], array('language' => $language, 'attributes' => array('class' => array($class)))) ; ?>
                                                    </li>
                                                <?php endforeach; ?>
                                                </ul>
                                            <?php endif; ?>
                                        </li>
                            <?php endforeach; ?>
                            </ul>
                        </li>
                    </ul>
                <?php endif; ?>
            </li>
        <?php endforeach; ?>
    </ul>
<?php endif; ?>

