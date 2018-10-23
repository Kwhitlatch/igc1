<div class="dam-uri-search-close">
    <img src="http://live-fluke-ecm.pantheonsite.io/profiles/commerce_kickstart/modules/contrib/ctools/images/icon-close-window.png" alt="Close window" title="Close window">
</div>

<div id="modal-content" class="modal-content">
    <form action="/dam_uri_search_filter/ajax" method="post" id="dam-form-search-filter-form" accept-charset="UTF-8" class="ctools-use-modal-processed">
        <div>
            <input type="hidden" name="uri_id" value="edit-field-toc-image-large-und-0-dam-uri-search">

            <table class="dam-uri-search-filters">
                <tbody>
                    <tr>
                        <td>
                            <fieldset>
                                <label>Asset Type:</label>
                                <input type="checkbox" name="asset_type[]" value="document" />Document
                                <input type="checkbox" name="asset_type[]" value="executable" />Executable
                                <input type="checkbox" name="asset_type[]" value="image" />Image
                                <input type="checkbox" name="asset_type[]" value="manual" />Manual
                                <input type="checkbox" name="asset_type[]" value="video" />Video
                                <input type="checkbox" name="asset_type[]" value="zip_files" />Zip_files
                            </fieldset>
                        </td>
                        <td>
                        <?php if (!empty($languages)): ?>
                        <label>Language:</label>
                            <select name="language">
                                <option value="None" selected>None</option>
                            <?php foreach ($languages as $item => $value): ?>
                                  <option value="<?php print $item; ?>"><?php print $item; ?></option>
                            <?php endforeach; ?>
                            </select>
                        <?php endif; ?>
                        </td>
                    </tr>
                </tbody>
            </table>

            <div class="form-item form-type-textfield form-item-keywords">
                <label for="edit-keywords">Search for:</label>
                <input type="text" id="dam-uri-keyword" name="keywords" value="" size="60" maxlength="128" class="form-text"><button id="dam-uri-keyword-search" type="button">Search</button>
            </div>
        </div>
    </form>
    <div id="dam-uri-keyword-query-results"></div>
    <p></p>
    <p></p>
    <p></p>
</div>
