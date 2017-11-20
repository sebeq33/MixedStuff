(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .controller('MyController', MyController);

  /** @ngInject */
  function MyController() {
    var vm = this;
    vm.helloworld = 'helloworld bitches !!!!';
  }
})();
