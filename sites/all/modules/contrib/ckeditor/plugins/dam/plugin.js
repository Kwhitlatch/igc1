/**
 * 2016 - Fluke Corporation - Ankur Jana
 * Plugin for connecting to Digital Asset Management(DAM) application and perform CRU and Search operations 
 */

CKEDITOR.plugins.add('dam',
    {
        // The plugin initialization logic goes inside this method.
        init: function (editor) {

            CKEDITOR.on('dialogDefinition', function (ev) {
                console.log('in dialog def');
                console.log(ev);

                var dialogName = ev.data.name;
                var dialogDefinition = ev.data.definition.contents[1];
            });

			//service path
			serviceApiDomain = "http://data.fluke.com";
			
            // Place the icon path in a variable to make it easier to refer to it later.
            // "this.path" refers to the directory where the plugin.js file resides. 
            var iconPath = this.path + 'images/icon.png';
            var pluginDirectory = this.path;
			

            //linked damStyle.css
            editor.addContentsCss(pluginDirectory + 'styles/damStyle.css');

            var dialogCmd = new CKEDITOR.dialogCommand('damIntegrateDlg');
            var contentTypeFound = "";
            var globalVar = "";
            var test1 = [];
            var selectArrayAll = [];

            //variable for storing filters
            var filters = {};

            imageFolderPath = this.path;

            //below function is probably not required, delete code after verification
            //var createElement = (function () {
            //    // Detect IE using conditional compilation
            //    if (/*@cc_on @*//*@if (@_win32)!/*@end @*/false) {
            //        // Translations for attribute names which IE would otherwise choke on
            //        var attrTranslations =
            //        {
            //            "class": "className",
            //            "for": "htmlFor"
            //        };

            //        var setAttribute = function (element, attr, value) {
            //            if (attrTranslations.hasOwnProperty(attr)) {
            //                element[attrTranslations[attr]] = value;
            //            }
            //            else if (attr == "style") {
            //                element.style.cssText = value;
            //            }
            //            else {
            //                element.setAttribute(attr, value);
            //            }
            //        };

            //        return function (tagName, attributes) {
            //            attributes = attributes || {};

            //            // See http://channel9.msdn.com/Wiki/InternetExplorerProgrammingBugs
            //            if (attributes.hasOwnProperty("name") ||
            //                attributes.hasOwnProperty("checked") ||
            //                attributes.hasOwnProperty("multiple")) {
            //                var tagParts = ["<" + tagName];
            //                if (attributes.hasOwnProperty("name")) {
            //                    tagParts[tagParts.length] =
            //                        ' name="' + attributes.name + '"';
            //                    delete attributes.name;
            //                }
            //                if (attributes.hasOwnProperty("checked") &&
            //                    "" + attributes.checked == "true") {
            //                    tagParts[tagParts.length] = " checked";
            //                    delete attributes.checked;
            //                }
            //                if (attributes.hasOwnProperty("multiple") &&
            //                    "" + attributes.multiple == "true") {
            //                    tagParts[tagParts.length] = " multiple";
            //                    delete attributes.multiple;
            //                }
            //                tagParts[tagParts.length] = ">";

            //                var element =
            //                    document.createElement(tagParts.join(""));
            //            }
            //            else {
            //                var element = document.createElement(tagName);
            //            }

            //            for (var attr in attributes) {
            //                if (attributes.hasOwnProperty(attr)) {
            //                    setAttribute(element, attr, attributes[attr]);
            //                }
            //            }

            //            return element;
            //        };
            //    }
            //        // All other browsers
            //    else {
            //        return function (tagName, attributes) {
            //            attributes = attributes || {};
            //            var element = document.createElement(tagName);
            //            for (var attr in attributes) {
            //                if (attributes.hasOwnProperty(attr)) {
            //                    element.setAttribute(attr, attributes[attr]);
            //                }
            //            }
            //            return element;
            //        };
            //    }
            //})();

            //function for base 64 conversion
            function encodeFileAsURL(fileElement) {

                var srcData = "";
                var filesSelected = fileElement.getInputElement().$.files;

                if (filesSelected.length > 0) {
                    var fileToLoad = filesSelected[0];
                    var fileReader = new FileReader();

                    fileReader.onload = function (fileLoadedEvent) {
                        srcData = fileLoadedEvent.target.result; // <--- data: base64
                        g_globalData.assetUploadBase64 = srcData;
                        //console.log("inside->" + g_globalData.assetUploadBase64);
                    }

                    fileReader.readAsDataURL(fileToLoad);
                }
            }
			
			//function for creating random ID
            function makeid() {
                var text = "";
                var possible = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

                for (var i = 0; i < 5; i++)
                    text += possible.charAt(Math.floor(Math.random() * possible.length));

                return text;
            }

            //function for fetching content types
            function fetchContentTypes() {

                var test = '{"document": "Document","executable": "Executable","image": "Image","video": "Video"}';
                var readResponse = "";
                var contentTypeIds = "";
                var contId = "";
                var contentTypeHtml = "";
                var contentTypeArr = [];

                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (xhttp.readyState == 4 && xhttp.status == 200) {
                        //contentTypeFound = xhttp.responseText;
                        //readResponse = JSON.parse(xhttp.responseText);
                        readResponse = JSON.parse(test);
                        contentTypeIds = Object.keys(readResponse);
                        for (var count in contentTypeIds) {
                            contId = contentTypeIds[count];
                            contentTypeHtml = [contId, readResponse[contId]];
                            contentTypeArr.push(contentTypeHtml);
                        }
                        contentTypeFound = contentTypeArr;
                    }
                };
                xhttp.open("POST", serviceApiDomain + "/api/dam_service_resources/GetSupportedContentTypes.json", true);

                xhttp.send();
            }
			

            /* function renderContentTypes() {
                var contentTypeHtml = "";
                var contTypeArr = {
                    document: "Document",
                    executable: "Executable",
                    image: "Image",
                    video: "Video"
                };
                //var contTypeArr = [["document":"Document"], ["executable":"Executable"], ["image":"Image"], ["video":"Video"]];
                var contentTypeFound2 = [["Saab", "saab"], ["Volvo", "volvo"], "BMW"];
                var contentTypeFound2 = [];
                //contentTypeFound2.push("test","test");
                var itemCnt = Object.keys(contTypeArr).length;
                //var test = ['test', 'test'];

                var contType;
                for (contType in contTypeArr) {
                    //contentTypeHtml = '[/'' + contTypeArr[contType] + '/', ' + '/'' + contType + '/']';
                    contentTypeHtml = [contTypeArr[contType], contType];
                    contentTypeFound2.push(contentTypeHtml);

                }

                return contentTypeFound2;
            } */

            function setSelectedAsset() {
                console.log('in set selected asset');
            }

            //function to execute search
            function searchAssets(contentType, taxonomyFilter, searchString, elementObj) {


                //var isFormDataSupported = !!window.FormData;
                //console.log(g_resultsThumbElem.getElement());
                var resultsFound = false;		

                if (window.FormData) {

                    if (taxonomyFilter == "") {
                        taxonomyFilter = "all";
                    }

                    var data = new FormData();
                    data.append("content_type", contentType);
                    data.append("taxonomy", taxonomyFilter);

                    if (searchString != "") {
                        data.append("search_string", searchString);
                    }

                    var xhr = new XMLHttpRequest();
                    //xhr.withCredentials = true;
                    var resultTitle = "";

                    //element.clear();
                    elementObj.getElement().hide();
                    vboxImgProps.getElement().hide();
                    vboxVidProps.getElement().hide();

                    xhr.addEventListener("readystatechange", function () {
                        if (this.readyState === 4) {
							
							//enable the search button after getting response
							g_buttonSearch.enable();
							
							//hide loading gif when response received							
							g_loadingGif.getElement().hide();
														
                            var responseJsonObj = JSON.parse(this.responseText);
                            g_globalData.resultsJsonObj = responseJsonObj;

                            renderResultsGrid(responseJsonObj, contentType);

                            console.log(responseJsonObj.nodes.length);

                            if (responseJsonObj.nodes.length > 0) {
                                resultsFound = true;
                            }
							
                            elementObj.getElement().show();

                            if (resultsFound) {
                                if (contentType == 'image') {
                                    vboxImgProps.getElement().show();
                                } else if (contentType == 'video') {
                                    vboxVidProps.getElement().show();
                                }

                            }

                        }
                    });

                    xhr.open("POST", serviceApiDomain + "/api/dam_service_resources/SearchAssets", true);
                    xhr.send(data);

                }
                else {
                    jQuery.support.cors = true;
                    alert('not supported');
                }



            }

            function renderCell(argResultTitle, argAssetUrl) {
                var renderHtml = "";

                return
            }

            function renderResultsGrid(jsonResultsObject, contentType) {

                var renderHtml = "";

                //var renderHtml_test = "";
                //renderHtml_test='<div class="clearfix" style="height: 100px; width: 400px; background-color: yellow; overflow-y: auto; overflow-x: auto;"><table><tr><td>1</td><td>2</td><td>3</td></tr></table></table></div>';

                var responseJsonObj = jsonResultsObject;
                var columnCount = 5;
                var itemCount = 0;
                var resultTitle_short;
                var assetUrl;

                //renderHtml = '<div class="imageBox"></div>';
                renderHtml = '<table id="tblResultsThumb" class="divTblResult">';
                for (var obj in responseJsonObj.nodes) {
                    //console.log(responseJsonObj.nodes[obj].node.id);

                    if (responseJsonObj.nodes[obj].node.id != 0) {
                        resultTitle = responseJsonObj.nodes[obj].node.title;

                        //console.log(responseJsonObj.nodes[obj].node.url);

                        if (resultTitle.length > 12) {
                            resultTitle_short = resultTitle.substr(0, 11) + '...';
                        }
                        else {
                            resultTitle_short = resultTitle;
                        }

                        assetUrl = responseJsonObj.nodes[obj].node.url;

                        if (itemCount == 0) {
                            renderHtml += '<tr>';
                        }

                        if (contentType == 'document') {
                            renderHtml += '<td title="' + resultTitle + '" style="text-align:center" class="tdTblResult grad">' +
                                '<div class="resultIcon" data-astUrl="' + assetUrl + '" data-astTitle="' + resultTitle + '">' +
                                '<div style="text-align:center;"><img src="' + imageFolderPath + 'images/dam_doc.png" style="height: 30px; width: 30px" /></div>' +
                                '<div style="text-align:center;">' + resultTitle_short + '</div>' +
                                '</div>' +
                                '</td>';

                        }
                        else if (contentType == 'image') {
                            renderHtml += '<td title="' + resultTitle + '" style="text-align:center" class="tdTblResult grad">' +
                                '<div class="resultIcon" data-astUrl="' + assetUrl + '" data-astTitle="' + resultTitle + '">' +
                                '<div style="text-align:center;"><img src="' + assetUrl + '" style="height: 30px; width: 30px" /></div>' +
                                '<div style="text-align:center;">' + resultTitle_short + '</div>' +
                                '</div>' +
                                '</td>';
							/* renderHtml += "<td><img src=/"" + responseJsonObj.nodes[obj].node.url + "/" style=/"height: 30px; width: 30px/" />" + itemCount +
								'</td>'; */

                        }
                        else if (contentType == 'executable') {
							renderHtml += '<td title="' + resultTitle + '" style="text-align:center" class="tdTblResult grad">' +
                                '<div class="resultIcon" data-astUrl="' + assetUrl + '" data-astTitle="' + resultTitle + '">' +
                                '<div style="text-align:center;"><img src="' + imageFolderPath + 'images/dam_exe.png" style="height: 30px; width: 30px" /></div>' +
                                '<div style="text-align:center;">' + resultTitle_short + '</div>' +
                                '</div>' +
                                '</td>';
                            /* renderHtml += '<td><img src="' + imageFolderPath + 'images/dam_exe.png" style="height: 30px; width: 30px" />' + itemCount +
                                '</td>'; */

                        }
                        else if (contentType == 'video') {
							renderHtml += '<td title="' + resultTitle + '" style="text-align:center" class="tdTblResult grad">' +
                                '<div class="resultIcon" data-astUrl="' + assetUrl + '" data-astTitle="' + resultTitle + '">' +
                                '<div style="text-align:center;"><img src="' + imageFolderPath + 'images/dam_vid.png" style="height: 30px; width: 30px" /></div>' +
                                '<div style="text-align:center;">' + resultTitle_short + '</div>' +
                                '</div>' +
                                '</td>';							
                            /* renderHtml += '<td><img src="' + imageFolderPath + 'images/dam_vid.png" style=" height: 30px; width: 30px" />' + itemCount +
                                '</td>'; */

                        }

                        itemCount++;

                        if (itemCount % columnCount == 0) {
                            renderHtml += '</tr><tr>';
                        }

                    }
                }

                if (itemCount % columnCount != 0) {
                    var intCount = itemCount % columnCount;
                    for (i = 0; i <= intCount; i++) {
                        renderHtml += '<td></td>';
                    }
                    renderHtml += '</tr>';
                }

                renderHtml += "</table></div>";
				
                g_resultsThumbElem.getElement().setHtml(renderHtml);
                //g_resultsThumbElem.getElement().setHtml(renderHtml_test);

                g_resultsThumbElem.getElement().show();
            }

            function populateAttributes(dialogObj, selectedAstUrl) {

                var captionElem = dialogObj.getContentElement('tabSearchAsset', 'txtCaption');
                var altTextElem = dialogObj.getContentElement('tabSearchAsset', 'txtAltText');

                for (obj in g_globalData.resultsJsonObj.nodes) {

                    //console.log(g_globalData.resultsJsonObj.nodes[obj].node.display_title);
                    //console.log(g_globalData.resultsJsonObj.nodes[obj].node.caption);
                    if (selectedAstUrl == g_globalData.resultsJsonObj.nodes[obj].node.url) {
                        //console.log(g_globalData.resultsJsonObj.nodes[obj].node.caption);
                        captionElem.setValue(g_globalData.resultsJsonObj.nodes[obj].node.caption);
                        altTextElem.setValue(g_globalData.resultsJsonObj.nodes[obj].node.display_title);
                    }
                }
            }

            function assetToEditor(dialogObj) {
                // Create a link element and an object that will store the data entered in the dialog window.
                // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.document.html#createElement
                //var dialog = this,
                //
                var data = {},
                    link = editor.document.createElement('a');

                // Populate the data object with data entered in the dialog window.
                // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dialog.html#commitContent
                dialogObj.commitContent(data);

                var elemFig;
                var elemFigCaption;
                var elemVideo = editor.document.createElement('video');
                var elemSource = editor.document.createElement('source');

                console.log(data.selectContentType);

                if (data.selectContentType == "document") {
                    link = editor.document.createElement('a');
                    //link.setAttribute('href', data.selectedAssetUrl);
                    //link.setAttribute('src', g_globalData.selectItemToEditor);
                    link.setAttribute('href', g_globalData.selectedAssetUrl);
                    //link.setHtml(data.selectAssetTitle);
                    link.setHtml(g_globalData.selectAssetTitle);
                }
                else if (data.selectContentType == "image") {

                    link = editor.document.createElement('img');
                    link.setAttribute('src', g_globalData.selectedAssetUrl);
                    //link.setAttribute('src', g_globalData.selectItemToEditor);
                    link.setAttribute('alt', g_globalData.imageAltText);

                    if (data.imageHeight != "") {
                    link.setAttribute('height', data.imageHeight);
                    }
                    //Changes Made by ankur
                    else
                    {
                        alert('Height is required !');
                        return ;
                    }

                    if (data.imageWidth != "") {
                        link.setAttribute('width', data.imageWidth);
                    }
                    //Changes Made by ankur
                    else{
                        alert('Width is required !');
                        return ;
                    }

                    link.setAttribute('align',data.imageAlignment);

                    if (data.imageCaptionShow) {

                        //create figure element
                        elemFig = editor.document.createElement('figure');
                        elemFig.setAttribute('class', data.imageCaptionClass);
                        

                        //create figure caption element
                        elemFigCaption = editor.document.createElement('figcaption');
                        elemFigCaption.setHtml(data.imageCaption);

                        //create final image with caption for render
                        elemFig.setHtml(link.getOuterHtml() + elemFigCaption.getOuterHtml());
                    }

                    //console.log(link.getOuterHtml());
                    //console.log(link.getHtml());
                    //console.log(data.imageCaptionShow);                        

                    //link.setHtml(data.selectAssetTitle);
                    //link.setHtml("image_added");
                }
                else if (data.selectContentType == "video") {

                    elemVideo.setAttribute('controls', '');


                    if (data.videoWidth != "") {
                        elemVideo.setAttribute('width', data.videoWidth);
                    }

                    if (data.videoHeight != "") {
                        elemVideo.setAttribute('height', data.videoHeight);
                    }

                    elemSource.setAttribute('src', data.selectedAssetUrl);
                    var fileExt = data.selectedAssetUrl.substr(data.selectedAssetUrl.lastIndexOf('.') + 1);
                    elemSource.setAttribute('type', 'video/' + fileExt);

                    elemVideo.setHtml(elemSource.getOuterHtml());
                    //elemVideo.setHtml('<source src="http://data.fluke.com/sites/default/files/P4Gtraining.mp4" type="video/mp4" />');
                    //elemSource = null;
                }
                else if (data.selectContentType == "executable") {
                    link = editor.document.createElement('a');
                    link.setAttribute('href', data.selectedAssetUrl);
                    link.setHtml(data.selectAssetTitle);
                }

                // Set the URL (href attribute) of the link element.
                // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.element.html#setAttribute


                // In case the "newPage" checkbox was checked, set target=_blank for the link element.
                //if (data.newPage)
                //    link.setAttribute('target', '_blank');

                // Set the style selected for the link, if applied.
                // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.element.html#setStyle
                //switch (data.style) {
                //    case 'b':
                //        link.setStyle('font-weight', 'bold');
                //        break;
                //    case 'u':
                //        link.setStyle('text-decoration', 'underline');
                //        break;
                //    case 'i':
                //        link.setStyle('font-style', 'italic');
                //        break;
                //}

                // Insert the Displayed Text entered in the dialog window into the link element.
                // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.element.html#setHtml
                //link.setHtml('asset');

                //alert(typeof(data.selectContentType));

                switch (data.selectContentType) {

                    case 'document':
                        editor.insertElement(link);
                        break;

                    case 'executable':
                        editor.insertElement(link);
                        break;

                    case 'image':
                        if (data.imageCaptionShow) {
                            editor.insertElement(elemFig);
                        }
                        else {
                            // Insert the link element into the current cursor position in the editor.
                            // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.editor.html#insertElement
                            editor.insertElement(link);
                        }
                        break;

                    case 'video':
                        editor.insertElement(elemVideo);
                        break;
                }

                //editor.insertElement(elemVideo);
                //remove results table from DOM
                //jQuery('#' + tblResultsId).hide();
            }

            //function to get languages and populate drop down
            function getLanguages(element) {
                var xhr = new XMLHttpRequest();

                xhr.addEventListener("readystatechange", function () {
                    if (this.readyState === 4) {

                        var responseJsonObj = JSON.parse(this.responseText);
                        var dataObj = responseJsonObj[1];
                        var itemFound = false;

                        for (var obj in dataObj) {
                            element.add(dataObj[obj].name, dataObj[obj].language);
                            itemFound = true;
                        }

                        if (itemFound) {
                            element.enable();
                            element.getElement().show();
                        }

                    }
                });

                xhr.open("POST", serviceApiDomain + "/api/dam_service_resources/GetEnabledLanguages.json", true);
                xhr.send();
            }

            //function to get meta data and populate meta data dropdowns
            function GetMetaData(contentType, searchParams) {

                var dataToPost = new FormData();
                dataToPost.append("content_types[0]", contentType);

                var xhr = new XMLHttpRequest();
                var searchParmasArr = searchParams;

                xhr.addEventListener("readystatechange", function () {
                    if (this.readyState === 4) {

                        var responseJsonObj = JSON.parse(this.responseText);
                        var searchResults = responseJsonObj[0];
                        var searchCriteriaItems = "";
                        var itemFound = "false";

                        for (var objParamDd in searchParmasArr) {

                            //clear the dropdown before populating data
                            searchParmasArr[objParamDd].clear();

                            //add default
                            searchParmasArr[objParamDd].add('- Any - ', '');

                            for (var objParam in searchResults) {

                                if (searchParmasArr[objParamDd].label.toLowerCase().replace(': ', '') == objParam.toLowerCase()) {
                                    searchCriteriaItems = searchResults[objParam];
                                    for (var objKey in searchCriteriaItems) {
                                        searchParmasArr[objParamDd].add(searchCriteriaItems[objKey].name, searchCriteriaItems[objKey].tid);
                                        itemFound = 'true';
                                    }

                                    if (itemFound == 'true') {
                                        searchParmasArr[objParamDd].enable();
                                        searchParmasArr[objParamDd].getElement().show();
                                    }
                                }
                            }
                        }

                        g_buttonSearch.enable();
                    }
                });

                xhr.open("POST", serviceApiDomain + "/api/dam_service_resources/GetMetaData.json", true);
                xhr.send(dataToPost);

            }

			
			function ShowHideElement(elem, visibility){
				if(visibility){
					elem.getElement().show();
				}
				else{
					elem.getElement().hide();
				}
			}
			
            // Create an editor command that stores the dialog initialization command.
            editor.addCommand('openDialogCmd', dialogCmd);

            editor.addCommand('damIntegrationCmd', {
                exec: function (editor) {
                    //fetchContentTypes();
                    editor.execCommand("openDialogCmd");
                },
                async: false
            });

            // Create a toolbar button that executes the plugin command defined above.
            editor.ui.addButton('digitalAssetBtn',
                {
                    label: 'Insert Digital Asset',
                    command: 'damIntegrationCmd',
                    icon: iconPath
                });

            // Add a new dialog window definition containing all UI elements and listeners.
            CKEDITOR.dialog.add('damIntegrateDlg', function (editor) {
                return {

                    title: 'Asset Properties',
                    minWidth: 500,
                    minHeight: 200,
                    contents: [
                        {
                            id: 'tabSearchAsset',
                            label: 'Search',
                            elements: [
                                {
                                    type: 'html',
                                    html: '<p>Choose an asset type to search: </p>',
                                    style: 'font-weight: bold;',
                                },
                                {
                                    type: 'radio',
                                    id: 'rdoAssetType',
                                    //label: 'Choose an asset type to search.',
                                    //labelLayout: 'horizontal',
                                    //items: contentTypeFound,
                                    items: [["Document", "document"], ["Executable", "executable"], ["Image", "image"], ["Video", "video"]],
                                    'default': 'image',

                                    onLoad: function (element) {
                                        // alert('onload');
                                        // fetchContentTypes();
                                    },
                                    commit: function (data) {
                                        data.selectContentType = this.getValue();
                                    },
                                    onChange: function () {
                                        var rdoBtnVal = this.getValue();
										
										//clear old search resuls and hide results pane


                                        if (rdoBtnVal == 'document') {

                                            //disable meta drop downs before search
                                            for (var keyType in selectArrayAll) {
                                                selectArrayAll[keyType].disable();
                                            }

                                            //get meta data for selected asset type and reload meta drop downs
                                            GetMetaData(rdoBtnVal, selectArrayAll);
                                        }
                                        else if (rdoBtnVal == 'executable') {
                                            //disable meta drop downs before search
                                            for (var keyType in selectArrayAll) {
                                                selectArrayAll[keyType].disable();
                                            }

                                            //get meta data for selected asset type and reload meta drop downs
                                            GetMetaData(rdoBtnVal, selectArrayAll);
                                        }
                                        else if (rdoBtnVal == 'image') {
                                            //disable meta drop downs before search
                                            for (var keyType in selectArrayAll) {
                                                selectArrayAll[keyType].disable();
                                            }

                                            //get meta data for selected asset type and reload meta drop downs
                                            GetMetaData(rdoBtnVal, selectArrayAll);
                                        }
                                        else if (rdoBtnVal == 'video') {
                                            //disable meta drop downs before search
                                            for (var keyType in selectArrayAll) {
                                                selectArrayAll[keyType].disable();
                                            }

                                            //get meta data for selected asset type and reload meta drop downs
                                            GetMetaData(rdoBtnVal, selectArrayAll);
                                        }
                                        else {
                                            alert('Oops! Something went wrong please refresh page.');
                                        }
                                    }

                                },
                                {
                                    type: 'text',
                                    id: 'txtSrchKeywords',
                                    label: 'Search Keywords: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    //validate: CKEDITOR.dialog.validate.notEmpty("Title field cannot be empty.")
                                },
                                {
                                    type: 'select',
                                    id: 'sltLanguage',
                                    label: 'Language: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [],
                                    onChange: function () {
                                        //if (this.getValue() == "") {
                                        //    delete filters.fltApplication;
                                        //} else {
                                        //    filters.fltApplication = this.getValue();
                                        //}
                                    }

                                },
                                {
                                    type: 'button',
                                    id: 'btnAdvFilters',
                                    label: 'Advanced Filters',
                                    title: 'Click for Advanced Filters',
                                    onClick: function () {
                                        var parentDialog = this.getDialog();
                                        var advFilters = parentDialog.getContentElement('tabSearchAsset', 'vboxAdvFilters');

                                        if (advFilters.isVisible()) {
                                            advFilters.getElement().hide();
                                        }
                                        else {
                                            advFilters.getElement().show();
                                        }
                                    }

                                },
                                {
                                    type: 'vbox',
                                    id: 'vboxAdvFilters',
                                    align: 'left',
                                    //width: '200px',
                                    children: [
                                        {
                                            type: 'html',
                                            html: '<p>Filter Selection: </p>',
                                            style: 'font-weight: bold;'
                                        },
                                        {
                                            type: 'radio',
                                            id: 'rdoFilterOpt',
                                            labelLayout: 'vertical',
                                            //label: 'Select Filter Type:',
                                            items: [["Include all", "all"], ["Include some", "some"]],
                                            'default': 'all'
                                        },
                                        {
                                            type: 'select',
                                            id: 'sltApplication',
                                            label: 'Application: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltApplication;
                                                } else {
                                                    filters.fltApplication = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltAstCat',
                                            label: 'Asset Category: ',
                                            widths: [116, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltAstCat;
                                                } else {
                                                    filters.fltAstCat = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltDocType',
                                            label: 'Document Type: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltDocType;
                                                } else {
                                                    filters.fltDocType = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltImgQlt',
                                            label: 'Image Quality: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltImgQlt;
                                                } else {
                                                    filters.fltImgQlt = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltIndustry',
                                            label: 'Industry: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltIndustry;
                                                } else {
                                                    filters.fltIndustry = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltLocaleIg',
                                            label: 'Locale - IG: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltLocaleIg;
                                                } else {
                                                    filters.fltLocaleIg = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltMac',
                                            label: 'Master Asset Container (MAC): ',
                                            widths: [107, 26],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltMac;
                                                } else {
                                                    filters.fltMac = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltMacType',
                                            label: 'Master Asset Container Type (MAC Type): ',
                                            widths: [240, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltMacType;
                                                } else {
                                                    filters.fltMacType = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltOpco',
                                            label: 'OpCo: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltOpCo;
                                                } else {
                                                    filters.fltOpCo = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltRegion',
                                            label: 'Region: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function () {
                                                if (this.getValue() == "") {
                                                    delete filters.fltRegion;
                                                } else {
                                                    filters.fltRegion = this.getValue();
                                                }
                                            }

                                        },
                                        {
                                            type: 'select',
                                            id: 'sltTopic',
                                            label: 'Topic: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [],
                                            onChange: function (data) {
                                                if (this.getValue() == "") {
                                                    delete filters.fltTopic;
                                                }
                                                else {
                                                    filters.fltTopic = this.getValue();
                                                }
                                            }
                                        }
                                    ]

                                },
                                {
                                    type: 'button',
                                    id: 'btnSearch',
                                    label: 'Search',
                                    title: 'Search Assets',
                                    className: 'btnSearch',
                                    style: 'font-weight: bold;',
                                    onClick: function () {
										
										
                                        var parentDialog = this.getDialog();
                                        var resultsList = parentDialog.getContentElement('tabSearchAsset', 'sltSearchResults');
                                        var searchKeywords = parentDialog.getContentElement('tabSearchAsset', 'txtSrchKeywords');
                                        var contentType = parentDialog.getContentElement('tabSearchAsset', 'rdoAssetType');
                                        var filterOpt = parentDialog.getContentElement('tabSearchAsset', 'rdoFilterOpt');
                                        var taxonomyFilter = "";
                                        var taxFilterLength = 0;

                                        if (filterOpt.getValue() == "all") {
                                            for (var filter in filters) {
                                                taxonomyFilter += filters[filter] + ",";
                                            }

                                        } else if (filterOpt.getValue() == "some") {
                                            for (var filter in filters) {
                                                taxonomyFilter += filters[filter] + "+";
                                            }

                                        }

                                        //remove trailing + or ,
                                        taxFilterLength = taxonomyFilter.length;
                                        if (taxFilterLength > 0) {
                                            if (taxonomyFilter.slice(taxFilterLength - 1, taxFilterLength) == "+" || taxonomyFilter.slice(taxFilterLength - 1, taxFilterLength) == ",") {
                                                taxonomyFilter = taxonomyFilter.substring(0, taxFilterLength - 1);
                                            }
                                        }

                                        //if no filters applied set taxonomy as "all"
                                        if (taxFilterLength == 0) {
                                            taxonomyFilter = "all";
                                        }

                                        //call search
                                        searchAssets(contentType.getValue(), taxonomyFilter, searchKeywords.getValue(), g_resultsThumbElem);
										
										//disable button till the search results show up
										this.disable();
										
										//show loading gif till the search results show up
										g_loadingGif.getElement().show();
										
										//reset properties
										g_txtAltText.setValue('');
										g_txtImgHeight.setValue('');
										g_txtImgWidth.setValue('');
										g_txtVidHeight.setValue('');
										g_txtVidWidth.setValue('');
										
                                        tblResultsId = g_resultsThumbElem.getElement().getId();
                                        //jQuery('#' + tblResultsId).hide();
                                        jQuery('#' + tblResultsId).on('click', 'td', function () {
                                            jQuery('#' + tblResultsId + ' td').css('background-image', 'linear-gradient(to top, #d3d3d3, #fff 50%)');
                                            //console.log(jQuery(this)[0].firstChild.src);
                                            //g_globalData.selectItemToEditor = jQuery(this)[0].firstChild.src;
                                            console.log(jQuery(this));

                                            //set parameters
                                            g_globalData.selectAssetTitle = jQuery(this)[0].firstChild.attributes['data-asttitle'].value;
                                            g_globalData.selectedAssetUrl = jQuery(this)[0].firstChild.attributes['data-asturl'].value;

                                            //show additional parameters to set if applicable
                                            populateAttributes(parentDialog, g_globalData.selectedAssetUrl);

                                            //
                                            jQuery(this).css('background-image', 'linear-gradient(to top, gray, #fff)');


                                        });

                                        jQuery('#' + tblResultsId).on('dblclick', 'td', function () {
                                            //console.log(parentDialog);
                                            console.log(this.title);

                                            //set parameters
                                            g_globalData.selectAssetTitle = jQuery(this)[0].firstChild.attributes['data-asttitle'].value;
                                            g_globalData.selectedAssetUrl = jQuery(this)[0].firstChild.attributes['data-asturl'].value;

                                            //add asset to editor and show the attributes if applicable
                                            assetToEditor(parentDialog);
                                            populateAttributes(parentDialog, g_globalData.selectedAssetUrl);

                                            //hide the dialog box
                                            parentDialog.hide();

                                            //unbind the double click event as the dialog is closing
                                            jQuery('#' + tblResultsId).unbind('dblclick');
                                        });
                                    }
                                },
								{
									type:'html',
									id: 'htmLoadingIcon',
									html:'<img src="'+imageFolderPath+'images/gears.gif">',
								},
                                {
                                    type: 'vbox',
                                    id: 'vboxSearchResults',
                                    align: 'left',
                                    //width: '200px',
                                    children: [
                                        /* {

                                            type: 'select',
                                            id: 'sltSearchResults',
                                            label: 'Results: ',
                                            // className: 'blank', 
                                            size: 15,
                                            style: 'height: 200px;',
                                            items: [
                                                ['Please Choose', '']
                                            ],
                                            commit: function (data) {
                                                var input = this.getInputElement().$;

                                                // data.selectAssetTitle = input.options[input.selectedIndex].text;
                                                // data.selectedAssetUrl = this.getValue();

                                                // console.log(input.options[input.selectedIndex].text);							        
                                                // console.log(this);
                                                // data.selectedAssetTitle = this
                                            },
                                            // style: 'visibility: hidden',
                                            onLoad: function (element) {
                                                // console.log('selectOnLoad');
                                                // this.add('Option 3', '1');
                                                // this.add('Option 4', '2');
                                                // this.removeClass('cke_dialog_ui_input_select');
                                            },
                                            onChange: function (element) {
                                                console.log(this.getValue());
                                                var parentDialog = this.getDialog();
                                                var captionElem = parentDialog.getContentElement('tabSearchAsset', 'txtCaption');
                                                var altTextElem = parentDialog.getContentElement('tabSearchAsset', 'txtAltText');

                                                for (obj in g_globalData.resultsJsonObj.nodes) {

                                                    if (this.getValue() == g_globalData.resultsJsonObj.nodes[obj].node.url) {
                                                        // console.log(g_globalData.resultsJsonObj.nodes[obj].node.caption);
                                                        captionElem.setValue(g_globalData.resultsJsonObj.nodes[obj].node.caption);
                                                        altTextElem.setValue(g_globalData.resultsJsonObj.nodes[obj].node.display_title);
                                                    }
                                                }
                                                // console.log(g_globalData.resultsJsonObj);
                                            }
                                        } */
										{
											type: 'html',
											id: 'showResultThumbnails',                                    
											html: '',
										},
                                    ]
                                },
                               
                                {
                                    type: 'vbox',
                                    id: 'vbxImgProps',
                                    children: [
                                        {
                                            type: 'checkbox',
                                            id: 'cbxCaption',
                                            label: 'Captioned Image',
                                            labelStyle: 'font-weight: bold; vertical-align: top',
                                            labelLayout: 'horizontal',
                                            commit: function (data) {
                                                data.imageCaptionShow = this.getValue();
                                            }
                                        },
                                        {
                                            type: 'text',
                                            id: 'txtCaption',
                                            label: 'Caption: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            commit: function (data) {
                                                data.imageCaption = this.getValue();

                                            }
                                        },
										
																		
                                        {
                                            type: 'select',
                                            id: 'selectCaptionClass',
                                            label: 'Caption Class: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            items: [["left-half", "left-half"], ["right-half", "right-half"],["full-width", "full-width"]],
											
                                            //'default': "left-half",
                                            commit: function (data) {
                                            data.imageCaptionClass = this.getValue();
											
                                            }
										
                                        },
										
                                        {
                                            type: 'text',
                                            id: 'txtAltText',
                                            label: 'Alt Text: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            commit: function (data) {
                                                data.imageAltText = this.getValue();
                                            }
                                        },
                                        {
                                            type: 'text',
                                            id: 'txtImgHeight',
                                            label: 'Height: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            commit: function (data) {
                                                data.imageHeight = this.getValue();
                                            }
                                        },
                                        {
                                            type: 'text',
                                            id: 'txtImgWidth',
                                            label: 'Width: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub; align: left',
                                            labelLayout: 'horizontal',
                                            commit: function (data) {
                                                data.imageWidth = this.getValue();
                                            }
                                        },
                                        
                                        {
                                            type: 'html',
                                            html: '<p>Alignment :</p>',
                                            style: 'font-weight: bold;'
                                        },
										
										
                                        {
                                            type: 'radio',
                                            id: 'rdoAlignment',
                                            items: [["Left", "left"], ["Right", "right"],["Center", "center"]],
                                            //'default': 'left',
                                            commit: function (data) {
                                                data.imageAlignment = this.getValue();
												//document.getElementById('rdoAlignment').href='styles/damStyle.css';
                                            }
                                        }
                                        


                                    ]
                                },
                                {
                                    type: 'vbox',
                                    id: 'vbxVidProps',
                                    children: [
                                        {
                                            type: 'text',
                                            id: 'txtVidHeight',
                                            label: 'Height: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub',
                                            labelLayout: 'horizontal',
                                            commit: function (data) {
                                                data.videoHeight = this.getValue();
                                            }
                                        },
                                        {
                                            type: 'text',
                                            id: 'txtVidWidth',
                                            label: 'Width: ',
                                            widths: [107, 268],
                                            labelStyle: 'font-weight: bold; vertical-align: sub; align: left',
                                            labelLayout: 'horizontal',
                                            commit: function (data) {
                                                data.videoWidth = this.getValue();
                                            }
                                        }
                                    ]
                                },

                            ]
                        },
                        {
                            id: 'tabAddAsset',
                            label: 'Add',
                            elements: [

                                {
                                    type: 'html',
                                    html: '<p>Choose an asset type to upload: </p>',
                                    style: 'font-weight: bold;'
                                },
                                {
                                    type: 'radio',
                                    id: 'rdoUldAssetType',
                                    //label: 'Choose an asset type to search.',
                                    //labelLayout: 'horizontal',
                                    items: [["Document", "document"], ["Executable", "executable"], ["Image", "image"], ["Video", "video"]],
                                    'default': 'document',

                                    onLoad: function (element) {
                                        //console.log('rdoOnLoad');
                                        test1 = [["document", "Document"], ["executable", "Executable"], ["image", "Image"], ["video", "Video"]];
                                        // alert('onload');
                                        // fetchContentTypes();
                                    },
                                    commit: function (data) {
                                        data.selectUldContentType = this.getValue();
                                    },

                                    setup: function (element) {
                                        //console.log('rdoSetup');
                                        //alert('test');
                                        //this.setValue(contentTypeFound);
                                        this.add('Option 3', '1');
                                    },
									
									
									onChange: function () {
                                        var rdoBtnVal = this.getValue();
										
										//hide following elements only applicable to images
										ShowHideElement(g_txtAddAltTag, false);
										ShowHideElement(g_txtAddImgCaption, false);

                                        if (rdoBtnVal == 'document') {

                                            //disable meta drop downs before search
                                            for (var keyType in selectArrUldAll) {
                                                selectArrUldAll[keyType].disable();
                                            }

                                            //get meta data for selected asset type and reload meta drop downs
                                            GetMetaData(rdoBtnVal, selectArrUldAll);
                                        }
                                        else if (rdoBtnVal == 'executable') {
                                            //disable meta drop downs before search
                                            for (var keyType in selectArrUldAll) {
                                                selectArrUldAll[keyType].disable();
                                            }

                                            //get meta data for selected asset type and reload meta drop downs
                                            GetMetaData(rdoBtnVal, selectArrUldAll);
                                        }
                                        else if (rdoBtnVal == 'image') {
                                            //disable meta drop downs before search
                                            for (var keyType in selectArrUldAll) {
                                                selectArrUldAll[keyType].disable();
                                            }

                                            //get meta data for selected asset type and reload meta drop downs
                                            GetMetaData(rdoBtnVal, selectArrUldAll);
											
											ShowHideElement(g_txtAddAltTag, true);
											ShowHideElement(g_txtAddImgCaption, true);
                                        }
                                        else if (rdoBtnVal == 'video') {
                                            //disable meta drop downs before search
                                            for (var keyType in selectArrUldAll) {
                                                selectArrUldAll[keyType].disable();
                                            }

                                            //get meta data for selected asset type and reload meta drop downs
                                            GetMetaData(rdoBtnVal, selectArrUldAll);
                                        }
                                        else {
                                            alert('Oops! Something went wrong please refresh page.');
                                        }
                                    }

                                },
                                {
                                    type: 'text',
                                    id: 'txtTitle',
                                    label: 'Title: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    //Changes Made by ankur
                                   // validate: CKEDITOR.dialog.validate.notEmpty("Title field cannot be empty"),
                                },
                                {
                                    type: 'text',
                                    id: 'txtUrlTitle',
                                    label: 'URL Title: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    //Changes Made by ankur
                                    //validate: CKEDITOR.dialog.validate.notEmpty("URL Title field cannot be empty"),
                                },
                                {
                                    type: 'select',
                                    id: 'sltUldLanguage',
                                    label: 'Language: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [],
                                    onChange: function () {
                                        //if (this.getValue() == "") {
                                        //    delete filters.fltApplication;
                                        //} else {
                                        //    filters.fltApplication = this.getValue();
                                        //}
                                    }

                                },
                                /* {
                                    type: 'file',
                                    id: 'uldAssetIcon',
                                    label: 'Asset Icon: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                },
                                {
                                    type: 'textarea',
                                    id: 'txtDesc',
                                    label: 'Description: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                }, */
                                {
                                    type: 'file',
                                    id: 'uldAsset',
                                    label: 'Asset: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    onChange: function (data) {
                                        //make this variable global on dialog show
                                        //g_globalData = {};
                                        //console.log(this);
                                        encodeFileAsURL(this);
                                        g_globalData.uploadedAsset = this.getInputElement().$.files[0];

                                        //console.log("in on change");
                                    }
                                },
                                {
                                    type: 'text',
                                    id: 'txtAddAltTag',
                                    label: 'Alt Tag: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                },
                                /* {
                                    type: 'text',
                                    id: 'txtSoftVer',
                                    label: 'Software Version: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                },
                                {
                                    type: 'text',
                                    id: 'txtVidUrl',
                                    label: 'Video URL: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                }, */
                                {
                                    type: 'text',
                                    id: 'txtAddImgCaption',
                                    label: 'Image Caption: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                },
                                /* {
                                    type: 'text',
                                    id: 'txtCreated',
                                    label: 'Created: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                },
                                {
                                    type: 'text',
                                    id: 'txtVidCaption',
                                    label: 'Video Caption: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                }, 
                                {
                                    type: 'select',
                                    id: 'sltProduct',
                                    label: 'Product: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [
                                        ['- Select - ', '-1']
                                    ],

                                }, */
                                {
                                    type: 'select',
                                    id: 'sltAddIndustry',
                                    label: 'Industry: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [
                                        ['- Select - ', '-1']
                                    ],

                                },
                                {
                                    type: 'select',
                                    id: 'sltAddApplication',
                                    label: 'Application: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [
                                        ['- Select - ', '-1']
                                    ],

                                },
                                {
                                    type: 'select',
                                    id: 'sltAddTopic',
                                    label: 'Topic: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [
                                        ['- Select - ', '-1']
                                    ],

                                },
                                {
                                    type: 'select',
                                    id: 'sltAddAward',
                                    label: 'Award: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [
                                        ['- Select - ', '-1']
                                    ],

                                },
                                {
                                    type: 'select',
                                    id: 'sltAddRegion',
                                    label: 'Region: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [
                                        ['- Select - ', '-1']
                                    ],

                                },
                                {
                                    type: 'select',
                                    id: 'sltAddOpco',
                                    label: 'OpCo: ',
                                    widths: [107, 268],
                                    labelStyle: 'font-weight: bold; vertical-align: sub',
                                    labelLayout: 'horizontal',
                                    items: [
                                        ['- Select - ', '-1']
                                    ],

                                },
                                {
                                    type: 'html',
                                    html: '<div id="datepicker"></div>' +
                                    '<link rel="stylesheet" href="//code.jquery.com/ui/1.11.4/themes/smoothness/jquery-ui.css">' +
                                    '<script src="//code.jquery.com/jquery-1.10.2.js"></script>' +
                                    '<script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>' +
                                    '<script>' +
                                    'jQuery( "#datepicker" ).datepicker();' +
                                    '</script>',
                                },
                                /* {
                                    type: 'text',
                                    id: 'abbr',
                                    label: 'Abbreviation',
                                    //validate: CKEDITOR.dialog.validate.notEmpty("Abbreviation field cannot be empty.")
                                }, */
                                {
                                    type: 'button',
                                    id: 'btnCreateAsset',
                                    label: 'Create',
                                    title: 'Create Asset',
                                    onClick: function () {

                                        var parentDialog = this.getDialog();
                                        var assetTitle = parentDialog.getContentElement('tabAddAsset', 'txtTitle');
                                        var assetUrlTitle = parentDialog.getContentElement('tabAddAsset', 'txtUrlTitle');
                                        var addContentType = parentDialog.getContentElement('tabAddAsset', 'rdoUldAssetType');
                                        var langUld = parentDialog.getContentElement('tabAddAsset', 'sltUldLanguage');

                                        var assetIcon = parentDialog.getContentElement('tabAddAsset', 'uldAssetIcon');
                                        var mainAsset = parentDialog.getContentElement('tabAddAsset', 'uldAsset');

                                         //Changes Made by ankur
                                         if(assetTitle.getValue()==""){
                                            console.log("Inside Message");
                                            alert('Title Can not be blank');
                                         }

                                         if(assetUrlTitle.getValue()==""){
                                            console.log("Inside Message");
                                            alert('URL Title can not be blank');
                                         }


                                        //var base64Data = encodeFileAsURL(mainAsset);

                                        //console.log(base64Data);
                                        //var base64 = $('#imgTest img').prop('src');
                                        var arr = g_globalData.assetUploadBase64.split('base64,');
                                        console.log('create on click');
                                        console.log(g_globalData.uploadedAsset);

                                        var fileData = {
                                            "file": {
                                                "file": arr[1],
                                                //"file": g_globalData.assetUploadBase64,
                                                "filename": g_globalData.uploadedAsset.name,
                                                //"filepath": "public://" + makeid() + g_globalData.uploadedAsset.name, /* in D7 change this value to "public://my_image.jpg" */
                                                "filepath": "public://" + g_globalData.uploadedAsset.name,
												//"filemime": "video/mp4",
												//"filetype": g_globalData.uploadedAsset.type,
                                            }
                                        };
										
										var assetLanguage = langUld.getValue();
										
										//create parameters for adding
										var varDispTitle = "field_display_title["+assetLanguage+"][0][value]";
										var varUrlTitle = "field_url_title["+assetLanguage+"][0][value]";
										var varTitleField = "title_field[und][0][value]";
										var varAssetId;
										
										var varContentType = addContentType.getValue().toLowerCase();
										
										if(varContentType == "document"){
											//field is translatable
											varAssetId = "field_document["+assetLanguage+"][0][fid]";
											
										}else if(varContentType == "image"){
											//field is not translatable
											varAssetId = "field_image[und][0][fid]";
											
										}else if(varContentType == "video"){
											//field is translatable
											varAssetId = "field_uploaded_video["+assetLanguage+"][0][fid]";
											
										}else if(varContentType == "executable"){
											//field is not translatable
											varAssetId = "field_executable_file[und][0][fid]";
										} 
											
																				
                                        jQuery.ajax({
                                            type: "POST",
                                            //url: "http://localhost:81/flukedamlocal/damservice/file.json",
                                            url: serviceApiDomain + "/api/file",
											//url: "http://dev-fluke-dam.pantheonsite.io/api/file",
                                            data: fileData,
                                            dataType: "json",
                                            success: function (result) {
                                                if (result.fid !== '') {
                                                    console.log('file uploaded');
                                                }

                                                var nodedata = {
                                                    "title": assetTitle.getValue(),
													[varTitleField]: assetTitle.getValue(),
                                                    "type": addContentType.getValue(),
                                                    "language": langUld.getValue(),  													
													[varDispTitle] : assetTitle.getValue(),
													[varAssetId]: result.fid,
                                                   /*  "field_document": {
                                                        "en": [{
                                                            "fid": result.fid
                                                        }]
                                                    }, */
                                                    //"url_title": assetUrlTitle.getValue(),
													[varUrlTitle]: assetUrlTitle.getValue(),
                                                };
												
												//nodedata.push(field_display_title);
												
												console.log(nodedata);

                                                jQuery.ajax({
                                                    //    url: "http://localhost:81/flukedamlocal/damservice/node.json",
                                                    url: serviceApiDomain + "/api/node.json",
                                                    type: 'post',
                                                    data: nodedata,
                                                    dataType: 'json',
                                                    //headers: {
                                                    //    'X-CSRF-Token': token
                                                    //},
                                                    error: function (XMLHttpRequest, textStatus, errorThrown) {
                                                        console.log('error ' + errorThrown);
                                                    },
                                                    success: function (data) {
                                                        console.log("Node created");
                                                    }
                                                });
                                            }
                                        });
                                    }
                                },
                            ]
                        }
                    ],

                    onLoad: function () {
                        var currTab = this;



                        // Act on tab switching
                        currTab.on('selectPage', function (e) {
                            console.log(e.data.page);
                            if (e.data.page == 'tabAddAsset') {
                                getLanguages(g_sltUldLanguage);
                                GetMetaData(g_radioElemUldAstType.getValue(), selectArrUldAll);
                                //sltUldLanguage
                            }
                            //console.log(currTab);
                            //console.log(currTab._.currentTabId);
                        });
                    },

                    onSetupContent: function () {
                        //console.log('setupContent');


                    },

                    onShow: function () {

                        //for moving dialog to any position in window
						/* console.log(this.getSize().width);
						console.log(this.getSize().height);
						console.log(this.getPosition().x);
						console.log(this.getPosition().y); */
                        this.move(this.getPosition().x, 50);
						
						//global array for storing variables
                        g_globalData = {};
						
                        g_resultsThumbElem = this.getContentElement('tabSearchAsset', 'showResultThumbnails');

                        //search assets elements
                        g_radioElem = this.getContentElement('tabSearchAsset', 'rdoAssetType');
                        //g_selectElem = this.getContentElement('tabSearchAsset', 'sltSearchResults');
                        g_selectLang = this.getContentElement('tabSearchAsset', 'sltLanguage');
                        g_selectApplication = this.getContentElement('tabSearchAsset', 'sltApplication');
                        g_selectAstCat = this.getContentElement('tabSearchAsset', 'sltAstCat');
                        g_selectDocType = this.getContentElement('tabSearchAsset', 'sltDocType');
                        g_selectImgQlt = this.getContentElement('tabSearchAsset', 'sltImgQlt');
                        g_selectIndustry = this.getContentElement('tabSearchAsset', 'sltIndustry');
                        g_selectLocaleIg = this.getContentElement('tabSearchAsset', 'sltLocaleIg');
                        g_selectMac = this.getContentElement('tabSearchAsset', 'sltMac');
                        g_selectMacType = this.getContentElement('tabSearchAsset', 'sltMacType');
                        g_selectOpco = this.getContentElement('tabSearchAsset', 'sltOpco');
                        g_selectRegion = this.getContentElement('tabSearchAsset', 'sltRegion');
                        g_selectTopic = this.getContentElement('tabSearchAsset', 'sltTopic');
                        g_vbxAdvFilters = this.getContentElement('tabSearchAsset', 'vboxAdvFilters');
						g_resultsThumbElem = this.getContentElement('tabSearchAsset', 'showResultThumbnails');
						g_loadingGif = this.getContentElement('tabSearchAsset', 'htmLoadingIcon');

                        g_buttonSearch = this.getContentElement('tabSearchAsset', 'btnSearch');
                        vboxVidProps = this.getContentElement('tabSearchAsset', 'vbxVidProps');
                        vboxImgProps = this.getContentElement('tabSearchAsset', 'vbxImgProps');
						g_txtAltText = this.getContentElement('tabSearchAsset', 'txtAltText');
						g_txtImgHeight = this.getContentElement('tabSearchAsset', 'txtImgHeight');
						g_txtImgWidth = this.getContentElement('tabSearchAsset', 'txtImgWidth');
						g_txtVidHeight = this.getContentElement('tabSearchAsset', 'txtVidHeight');
						g_txtVidWidth = this.getContentElement('tabSearchAsset', 'txtVidWidth');

                        selectArrayAll = [g_selectApplication, g_selectAstCat, g_selectDocType, g_selectImgQlt, g_selectIndustry, g_selectLocaleIg, g_selectMac, g_selectMacType, g_selectOpco, g_selectRegion, g_selectTopic];

                        //add assets elements
                        g_radioElemUldAstType = this.getContentElement('tabAddAsset', 'rdoUldAssetType');
                        g_sltUldLanguage = this.getContentElement('tabAddAsset', 'sltUldLanguage');
						g_sltUldIndustry = this.getContentElement('tabAddAsset', 'sltAddIndustry');
						g_sltUldApplication = this.getContentElement('tabAddAsset', 'sltAddApplication');
						g_sltUldTopic = this.getContentElement('tabAddAsset', 'sltAddTopic');
						g_sltUldAward = this.getContentElement('tabAddAsset', 'sltAddAward');
						g_sltUldOpco = this.getContentElement('tabAddAsset', 'sltAddOpco');
                        g_sltUldRegion = this.getContentElement('tabAddAsset', 'sltAddRegion');
						g_txtAddAltTag = this.getContentElement('tabAddAsset', 'txtAddAltTag');
						g_txtAddImgCaption = this.getContentElement('tabAddAsset', 'txtAddImgCaption');


                        selectArrUldAll = [g_sltUldIndustry, g_sltUldApplication, g_sltUldTopic, g_sltUldAward, g_sltUldOpco, g_sltUldRegion];

                        //disable and hide the fields before getting data from server(search tab)
                        for (var keyType in selectArrayAll) {
                            selectArrayAll[keyType].disable();
                            selectArrayAll[keyType].getElement().hide();
                        }

                        //disable and hide the fields before getting data from server(add tab)
                        for (var keyType in selectArrUldAll) {
                            selectArrUldAll[keyType].disable();
                            selectArrUldAll[keyType].getElement().hide();
                        }
						
						//hide image parameters for add tab
						g_txtAddAltTag.getElement().hide();
						g_txtAddImgCaption.getElement().hide();
						
                        //disable and hide languages
                        g_selectLang.disable();
                        g_selectLang.getElement().hide();

                        //Hide the search results list box on dialog load
                        //g_selectElem.getElement().hide();
						
						//Hide loading icon
						g_loadingGif.getElement().hide();

                        //Hide the search results list grid
                        g_resultsThumbElem.getElement().hide();

                        //Hide advanaced filters
                        g_vbxAdvFilters.getElement().hide();

                        //Hide image properties box
                        vboxImgProps.getElement().hide();

                        //Hide video properties box
                        vboxVidProps.getElement().hide();

                        //Disable Search Button
                        g_buttonSearch.disable();

                        //Load meta data on load
                        GetMetaData(g_radioElem.getValue(), selectArrayAll);

                        //get languages
                        getLanguages(g_selectLang);
                    },

                    onOk: function () {
                        // Create a link element and an object that will store the data entered in the dialog window.
                        // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.document.html#createElement
                        var dialog = this,
                            data = {},
                            link = editor.document.createElement('a');

                        // Populate the data object with data entered in the dialog window.
                        // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dialog.html#commitContent
                        this.commitContent(data);

                        var elemFig;
                        var elemFigCaption;
                        var elemVideo = editor.document.createElement('video');
                        var elemSource = editor.document.createElement('source');

                    
                        if (data.selectContentType == "document") {
                            link = editor.document.createElement('a');
                            //link.setAttribute('href', data.selectedAssetUrl);
                            //link.setAttribute('src', g_globalData.selectItemToEditor);
                            link.setAttribute('href', g_globalData.selectedAssetUrl);
                            //link.setHtml(data.selectAssetTitle);
                            link.setHtml(g_globalData.selectAssetTitle);
                        }
                        else if (data.selectContentType == "image") {
                            console.log(g_globalData.selectedAssetUrl);

                            
                            if(g_globalData.selectedAssetUrl != undefined || g_globalData.selectedAssetUrl != ""){
                            link = editor.document.createElement('img');
                            link.setAttribute('src', g_globalData.selectedAssetUrl);
                            //link.setAttribute('src', g_globalData.selectItemToEditor);
                            link.setAttribute('alt', data.imageAltText);

                            if (data.imageHeight != "") {
                                link.setAttribute('height', data.imageHeight);
                            }
                            //Changes Made by ankur
                            /* else{
                                alert('Height of Image is Required !');
                                return false;
                            } */

                            if (data.imageWidth != "") {
                                link.setAttribute('width', data.imageWidth);
                            }
                            //Changes Made by ankur
                            /* else{
                                alert('Width of Image is Required !');
                                return false;
                            } */

                                link.setAttribute('align',data.imageAlignment);
                                console.log("Image Caption");
                                console.log(data.imageCaptionClass);

                            if (data.imageCaptionShow) {

                                //create figure element
                                elemFig = editor.document.createElement('figure');
                                elemFig.setAttribute('class', data.imageCaptionClass);
                                

                                //create figure caption element
                                elemFigCaption = editor.document.createElement('figcaption');
                                elemFigCaption.setHtml(data.imageCaption);

                                //create final image with caption for render
                                elemFig.setHtml(link.getOuterHtml() + elemFigCaption.getOuterHtml());
                            }
                        }

                            //console.log(link.getOuterHtml());
                            //console.log(link.getHtml());
                            //console.log(data.imageCaptionShow);                        

                            //link.setHtml(data.selectAssetTitle);
                            //link.setHtml("image_added");
                        }
                        else if (data.selectContentType == "video") {

                            elemVideo.setAttribute('controls', '');


                            if (data.videoWidth != "") {
                                elemVideo.
								
								setAttribute('width', data.videoWidth);
                            }

                            if (data.videoHeight != "") {
                                elemVideo.setAttribute('height', data.videoHeight);
                            }

                            elemSource.setAttribute('src', data.selectedAssetUrl);
                            var fileExt = data.selectedAssetUrl.substr(data.selectedAssetUrl.lastIndexOf('.') + 1);
                            elemSource.setAttribute('type', 'video/' + fileExt);

                            elemVideo.setHtml(elemSource.getOuterHtml());
                            //elemVideo.setHtml('<source src="http://data.fluke.com/sites/default/files/P4Gtraining.mp4" type="video/mp4" />');
                            //elemSource = null;
                        }
                        else if (data.selectContentType == "executable") {
                            link = editor.document.createElement('a');
                            link.setAttribute('href', data.selectedAssetUrl);
                            link.setHtml(data.selectAssetTitle);
                        }

                        // Set the URL (href attribute) of the link element.
                        // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.element.html#setAttribute


                        // In case the "newPage" checkbox was checked, set target=_blank for the link element.
                        //if (data.newPage)
                        //    link.setAttribute('target', '_blank');

                        // Set the style selected for the link, if applied.
                        // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.element.html#setStyle
                        //switch (data.style) {
                        //    case 'b':
                        //        link.setStyle('font-weight', 'bold');
                        //        break;
                        //    case 'u':
                        //        link.setStyle('text-decoration', 'underline');
                        //        break;
                        //    case 'i':
                        //        link.setStyle('font-style', 'italic');
                        //        break;
                        //}

                        // Insert the Displayed Text entered in the dialog window into the link element.
                        // http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.dom.element.html#setHtml
                        //link.setHtml('asset');

                        //alert(typeof(data.selectContentType));
						
						console.log(link);
						console.log(link.$.innerHTML);
						if(link.$.innerHTML!='undefined'){

							switch (data.selectContentType) {

								case 'document':
									editor.insertElement(link);
									break;

								case 'executable':
									editor.insertElement(link);
									break;

								case 'image':
									if (data.imageCaptionShow) {
										editor.insertElement(elemFig);
									}
									else {
										// Insert the link element into the current cursor position in the editor.
										// http://docs.cksource.com/ckeditor_api/symbols/CKEDITOR.editor.html#insertElement
										editor.insertElement(link);
									}
									break;

								case 'video':
									editor.insertElement(elemVideo);
									break;
							}
						}
						
						//unbind the click event as the dialog is closing
                        jQuery('#' + g_resultsThumbElem.getElement().getId()).unbind('click');

                        //editor.insertElement(elemVideo);
                        //remove results table from DOM
                        //jQuery('#' + tblResultsId).hide();
                    }
                };
            });
        }
    });