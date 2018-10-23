<div class="distributor" itemscope itemtype="http://schema.org/LocalBusiness">

  <h2 itemprop="name"><?php print $label; ?></h2>
    <?php if(!empty($plat_tech)) {

      // Modal to explain plat tech.
      // $what_this = ' <a class="plat-tech-modal-link" data-toggle="modal" data-target="#plat-tech-modal">' . t('What\'s this?') . '</a>';

      echo '<a href="'.$plat_tech_link.'" target="_blank"><h3>' . t('Platinum Technical Distributor'). '</h3></a>';
    }?>

  <div itemprop="address" itemscope itemtype="http://schema.org/PostalAddress">
    <?php if(!empty($premise)) print $premise . "<br />";?>
    <div itemprop="streetAddress"><?php print $address; ?></div>
    <div><span itemprop="addressLocality"><?php print $city.'</span> <span itemprop="addressRegion">'.$postal_code."</span></div>"; ?>
  </div>

  <div class="phone-fax">
  <?php if(!empty($phone)) print "<div><span class='phone-label'>" . t('Phone') . ":</span> <a href='tel:$phone' itemprop='telephone'>$phone</a></div>" ;?>
  <?php if(!empty($fax)) print "<div><span class='fax-label'>" . t('Fax') . ":</span> <span itemprop='faxNumber'>$fax</span></div>" ;?>
  </div>

  <div class="email">
  <?php if(!empty($email)) print "<span class='email-label'>" . t('Email') . ":</span> <a href='mailto:$email' itemprop='email'>$email</a>" ;?>
  </div>

  <?php if(!empty($website)) { ?>
  <a class="button distributor-website" href="<?php print $website?>" itemprop="url"> <?php print t('Website')?></a>
  <?php } ?>

</div>