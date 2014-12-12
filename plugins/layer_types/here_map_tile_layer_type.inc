<?php

class here_map_tile_layer_type extends openlayers_layer_type_image {

  function options_init(){
    return array(
      'vector' => FALSE
    ) + parent::options_init();
  }

}
