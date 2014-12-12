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
  var maxExtent;
    if (options.maxExtent === null) {
      // Stretch image to cover whole map if not specified.
      maxExtent = map.maxExtent;
    } else {
      maxExtent = options.maxExtent;
    }

    return new OpenLayers.Layer.Image(
      title,
      'http://2.base.maps.cit.api.here.com/maptile/2.1/maptile/newest/normal.day/11/525/761/256/png8?app_id=DemoAppId01082013GAL&app_code=AJKnXv84fjrb0KIHawS0Tg',
      OpenLayers.Bounds.fromArray(maxExtent),
      new OpenLayers.Size(options.size.w/options.factors.x, options.size.h/options.factors.y),
      {
        drupalID: options.drupalID,
        numZoomLevels: options.numZoomLevels,
        opacity: options.opacity,
        projection: new OpenLayers.Projection(options.projection),
        transitionEffect: options.transitionEffect,
        isBaseLayer: options.isBaseLayer,
        attribution: options.attribution
      }
    );
  };

    // var extent = [0, 0, 1024, 968];
    // var projection = new OpenLayers.proj.Projection({
    //   code: 'xkcd-image',
    //   units: 'pixels',
    //   extent: extent
    // });

    // var map = new OpenLayers.Map({
    //   layers: [
    //     new OpenLayers.layer.Image({
    //       source: new OpenLayers.source.ImageStatic({
    //         attributions: [
    //           new OpenLayers.Attribution({
    //             html: '&copy; <a href="http://xkcd.com/license.html">xkcd</a>'
    //           })
    //         ],
    //         url: 'http://2.base.maps.cit.api.here.com/maptile/2.1/maptile/newest/normal.day/11/525/761/256/png8?app_id=DemoAppId01082013GAL&app_code=AJKnXv84fjrb0KIHawS0Tg',
    //         projection: projection,
    //         imageExtent: extent
    //       })
    //     })
    //   ],
    //   target: 'map',
    //   view: new OpenLayers.View({
    //     projection: projection,
    //     center: ol.extent.getCenter(extent),
    //     zoom: 2
    //   })
    // });
