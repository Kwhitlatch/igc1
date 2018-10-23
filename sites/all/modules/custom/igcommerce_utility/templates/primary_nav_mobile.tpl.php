<?php if(!empty($items)): ?>
    <ul id="mobile-<?php print $language->language; ?>-nav">
        <?php foreach($items as $level1): ?>
            <?php if(isset($level1['show_children']) && $level1['show_children']): ?>
                <?php if($level1['destination'] == 'external'): ?>
                    <li class="mobile-top-lvl mobile-top-lvl-<?php print $level1['en_us_url']; ?>">
                      <?php print l($level1['name'], $level1['link'],
                        array('html' => TRUE,
                          'language' => $language,
                          'attributes' => array(
                            'class' => ['dropdown-toggle'],
                            'data-toggle' => 'dropdown',
                            'role' => 'button',
                            'aria-expanded' => 'false',
                            'aria-haspopup' => 'false')
                        )
                      );
                      ?>
                <?php else: ?>
                    <li class="mobile-top-lvl mobile-top-lvl-<?php print $level1['en_us_url']; ?>">
                        <?php print l($level1['name'], $level1['link'], array('language' => $language)); ?>
                    <?php endif; ?>
                        <?php if($level1['show_children'] && !empty($level1['children'])): ?>
                            <ul>
                                <?php foreach($level1['children'] as $level2): ?>
                                    <li class="mobile-second-lvl mobile-second-lvl-<?php print $level2['en_us_url']; ?>">
                                        <?php print l($level2['name'], $level2['link'], array('language' => $language)); ?>
                                        <?php if(isset($level2['show_children']) && !empty($level2['children'])): ?>
                                            <ul>
                                                <?php foreach($level2['children'] as $level3): ?>
                                                    <li>
                                                      <?php print l($level3['name'], $level3['link']); ?>
                                                    </li>
                                                <?php endforeach; ?>
                                            </ul>
                                        <?php endif; ?>
                                    </li>
                                <?php endforeach; ?>
                            </ul>
                        <?php endif; ?>  
                    </li>
            <?php else: ?>
                <?php if($level1['destination'] == 'external'): ?>
                    <li class="dropdown top-lvl-<?php print $level1['en_us_url']; ?>">
                      <?php print l($level1['name'], $level1['link'], array('language' => $language, 'attributes' => array('class' => ['dropdown-toggle']))); ?>
                    </li>
                <?php else: ?>
                    <li class="dropdown top-lvl-<?php print $level1['en_us_url']; ?>">
                      <?php print l($level1['name'], $level1['link'], array('language' => $language, 'attributes' => array('class' => ['dropdown-toggle'], 'data-toggle' => 'dropdown'))); ?>
                    </li>
                <?php endif; ?>
            <?php endif; ?>
        <?php endforeach; ?>
    </ul>
<?php endif; ?>

