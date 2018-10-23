<?php
    //echo '<pre>'.print_r($items, TRUE). '</pre>';
?>
<?php if ($found): ?>
    <?php if ($total > 0): ?>
        <b>Found: </b><?php print $total . ' '; ?> Assets found
    <?php endif; ?>
    <table id="dam-uri-search-result-wrapper">
        <tbody>
        <?php $i = 1; ?>
        <?php foreach ($items as $item => $value): ?>
            <?php
                if (is_object($value['asset_url'])) {
                    $file = $value['asset_url']->field_original_url;
                    $file_thumbnail = $value['asset_url']->field_thumbnail_url;
                } else {
                    $file = $value['asset_url'];
                };
            ?>
            <tr class="dam_uri_search_result <?php print $value['id']; ?>">
                <td><?php print $i; ?></td>
                <td>
                    <div  class="dam_uri_search_result_text"
                        data-asset-id="<?php print $value['id']; ?>"
                        data-asset-uri="<?php print $file; ?>"
                        data-asset-title="<?php print $value['title']; ?>"
                        data-asset-caption="<?php print $value['caption']; ?>"
                        data-asset-thumbnail="<?php print (isset($file_thumbnail) ? $file_thumbnail : ""); ?>">
                    <span><b>Asset Type: </b><?php print $value['type']; ?></span>
                    | <span><b>Lang: </b></span><?php print ' ' . $value['language'] . ' '; ?>
                    | <span><b>Node ID: </b><?php print $value['id']; ?></span></br>
                    <span><b>Label: </b></span><?php print ' ' . $value['title']; ?></br>
                    <span><b>File: </b></span><?php print ' ' . strlen($file) > 2 ? $file : "<span style='color:red;'>File Missing</span>"; ?>
                    </div>
                </td>
            </tr>
            <?php $i++; ?>
        <?php endforeach; ?>
        </tbody>
    </table>
<?php else: ?>
    <div class="dam_uri_search_result">Nothing found on server</div>
<?php endif; ?>
