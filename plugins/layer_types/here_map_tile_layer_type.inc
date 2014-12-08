<?php

class here_map_tile_layer_type extends openlayers_layer_type {

  public $disabled = false;
  public $name = 'Here Map Tile API';
  public $title = 'Here Map Tile API';
  public $description = 'Integrates the Here.com Map Tile API';
  public $LonLat = '';
  /**
  * Provide initial values for options.
  */
  function options_init() {
    global $language;
    $lang = $language->language;
    $culture = variable_get('here_layers_language', '');
    $lang = $lang .= '-' . strtoupper($lang);

    return array(
      'layer_handler' => 'here',
      'app_id' => variable_get('here_map_tile_app_id', ''),
      'app_code' => variable_get('here_map_tile_app_code', ''),
      'type' => 'Road',
      'culture' => $culture == '' ? $lang : $culture,
    ) + parent::options_init();
  }

  /**
  * Options form which generates layers
  */
  function options_form($defaults = array()) {
    $warning = ( !variable_get('here_map_tile_app_id', FALSE) || !variable_get('here_map_tile_app_code', FALSE) ) ? array (
      '#value' => t('WARNING: Your Here App ID or App Code is not set.  Maps including Here Layers will break until this is correctly configured.')
    ) : NULL;

    $here_tile_types = array(
      'Base' => t('Base Tiles'),
      'Aerial' => t('Aerial Tiles'),
      'Traffic' => t('Traffic Tiles'),
      'Pano' => t('Pano Tiles'),
    );

    $here_scheme_types = array(
      'normal.day' => t('Normal Day'),
      'normal.day.grey' => t('Normal Day - Grey'),
      'normal.day.transit' => t('Normal Day - Transit'),
      'normal.traffic.day' => t('Normal Traffic - Day'),
      'normal.traffic.night' => t('Normal Traffic - Night'),
      'normal.day.custom' => t('Normal map view in daylight mode'),
      'normal.night' => t('Normal map in Nightmode'),
      'normal.night.grey' => t('Normal map in Grey Nightmode'),
    );

    return array(
      'tile_type' => array(
        '#title' => t('Tile Type'),
        '#type' => 'select',
        '#default_value' => isset($this->data['tile_type']) ? $this->data['tile_type'] : 'Base',
        '#options' => $here_tile_types,
      ),
      'scheme_type' => array(
        '#title' => t('Scheme Type'),
        '#type' => 'select',
        '#default_value' => isset($this->data['scheme_type']) ? $this->data['scheme_type'] : 'normal.day',
        '#options' => $here_scheme_types,
      ),
      $warning
    );
  }

  /**
  * Layer-type-wide settings form
  */
  function settings_form() {
    $form['here_map_tile_app_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Here App Id'),
      '#description' => t('<a href="@here">Get a Here App ID</a>', array( '@here' => 'https://developer.here.com')),
      '#default_value' => variable_get('here_map_tile_app_id', ''),
    );

    $form['here_map_tile_app_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Here App Code'),
      '#default_value' => variable_get('here_map_tile_app_code', ''),
    );

    return $form;
  }

  /**
  * Render.
  */
  function render(&$map) {
    static $here_maps_included;

    if(!isset($here_maps_included)) {
      drupal_add_js(drupal_get_path('module', 'here') . '/plugins/layer_types/openlayers_layer_type_here.js', 'file');
      $here_maps_included = TRUE;
    }
  }

}
