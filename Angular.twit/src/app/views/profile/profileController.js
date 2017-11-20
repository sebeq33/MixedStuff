(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .controller('ProfileController', ProfileController);

  /** @ngInject */
  function ProfileController($routeParams, $http, baseUrl) {
    var vm = this;
    $http({
        method: 'GET',
        url: baseUrl + '/getProfile/'+$routeParams.user
    }).then(
        function(res) {
            vm.data = res.data;
            vm.totalXp = vm.data.xp + vm.data.remaining;
            vm.computedPercent = Math.floor(100*vm.data.xp / vm.totalXp);
        },
        function(fail) {
            console.log('Nope : ' + fail.data);
        });
  }
})();
