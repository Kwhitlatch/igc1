<?php
/**
 * @file
 * Displays the items of the accordion.
 *
 * @ingroup views_templates
 *
 * Note that the accordion NEEDS <?php print $row ?> to be wrapped by an
 * element, or it will hide all fields on all rows under the first field.
 *
 * Also, if you use field grouping and use the headers of the groups as the
 * accordion headers, these NEED to be inside h3 tags exactly as below
 * (though you can add classes).
 *
 * The current div wraping each row gets two css classes, which should be
 * enough for most cases:
 *     "views-accordion-item"
 *      and a unique per row class like item-0
 */

?>




    <li><?php if (!empty($title)): ?><a href="#"><?php print $title; ?></a><?php endif; ?>
        <ul>
        <?php foreach ($rows as $id => $row): ?>

                <li <?php if ($classes_array[$id]) { print ' class="mm-list ' . $classes_array[$id] .'"';  } ?>>
                    <?php print $row; ?>
                </li>
            <?php endforeach; ?>
        </ul>

    </li>
