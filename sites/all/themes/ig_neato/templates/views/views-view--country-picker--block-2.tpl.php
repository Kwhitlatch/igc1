<?php

/**
 * @file
 * Main view template.
 *
 * Custom template for mobile language picker
 *
 * @ingroup views_templates
 */
?>
    <div class="<?php print $classes; ?>">
        <?php if ($header): ?>
            <div class="view-header">
                <?php print $header; ?>
            </div>
        <?php endif; ?>

        <?php if ($rows): ?>
            <nav id="language-menu">
                <h2><?php print t('Select your country site'); ?></h2>
                <ul>
                    <?php print $rows; ?>


                </ul>
            </nav>
        <?php endif ?>


    </div>

