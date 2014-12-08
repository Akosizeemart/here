/**
  * Process Here Layers
  * @param layerOptions
  *  Object of options.
  * @param mapid
  *
  *
  *
  */
  Drupal.openlayers.layer.here_maps_tile_api = function(title, map, options) {
    options.long = "121.11877433488672";
    options.lat = "14.426700487886933";
    options.url = "http://2.base.maps.cit.api.here.com/maptile/2.1/maptile/newest/normal.day/11/525/761/256/png8?app_id=DemoAppId01082013GAL&app_code=AJKnXv84fjrb0KIHawS0Tg";
    return new OpenLayers.Layer.Image(options);
  };
