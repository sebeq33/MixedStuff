(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .config(config);

  /** @ngInject */
  function config(moment) {
    moment.locale('fr');
  }

})();
