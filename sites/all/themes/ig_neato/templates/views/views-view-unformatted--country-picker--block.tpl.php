
<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="country-group">
    <?php if (!empty($title)): ?>
        <h3><?php print $title; ?></h3>
    <?php endif; ?>
    <div class="language-set">
        (<?php foreach ($rows as $id => $row): ?>
            <span<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
                <?php print $row; ?>
            </span>
        <?php endforeach; ?>
        )

    </div>


</div>