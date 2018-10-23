<?php if(isset($items) && !empty($items)): ?>
    <div class="contextual-links-region panel-pane pane-block pane-menu-secondary-navigation pane-menu <?php print $bundle; ?>">
        <div class="pane-content">
            <ul class="menu">
                <?php foreach ($items as $item): ?>
                <li class="first leaf">
                  <?php
                  print l($item['title'], $item['link'], array(
                      'html' => TRUE,
                      'language' => $language,
                      'attributes' => array(
                        'target' => $item['target'],
                        'class' => $item['class'],
                        'title' => $item['title']))
                  )
                  ; ?>
                </li>
                <?php endforeach; ?>
            </ul>
        </div>
    </div>
<?php endif; ?>
