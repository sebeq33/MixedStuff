(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .component('headerComponent', headerComponent());

  /** @ngInject */
  function headerComponent() {
    var component = {
      templateUrl: 'app/views/header/header.html',
      bindings: {
      },
      controller: HeaderController,
      controllerAs: 'header',
    };
    return component;
  }

  /** @ngInject */
  function HeaderController(localStorageService, $location, LoginService, $scope) {
    var vm = this;
    this.logout=logout;
    vm.user=LoginService.user;
    vm.profilePage = function(){
        if (!vm.user) {
            $location.url('login');
        } else {
            $location.url('profile/' + vm.user.login);
        }
    };

    function logout() {
        LoginService.logout();
        $location.url('/');
    }

    function init() {
        LoginService.checkUserChanged($scope, function (e, user) {
            vm.user = user;
        });
    }
    init();
  }
})();
