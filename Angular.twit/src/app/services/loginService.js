(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .service('LoginService', LoginService);

  /** @ngInject */
  function LoginService($q, $http, localStorageService, baseUrl) {
      var vm = this;
      vm.login = login;
      vm.notify=notify;
      vm.logout=logout;
      vm.user=localStorageService.get('user');
      vm.checkUserChanged=checkUserChanged;
      var scopeStack = [];

      function checkUserChanged(scope, callback) {
          scopeStack.push(scope);
          scope.$on('userChanged', callback);
          scope.$on('$destroy', function() {
             scopeStack.splice(scopeStack.indexOf(scope), 1) ;
          });
      }

      function notify() {
          scopeStack.forEach(function(scope) {
             scope.$emit('userChanged', vm.user);
          });
      }

      function login(name, pass) {
        var deferred = $q.defer();
        var user = localStorageService.get('user');
        $http({
            method: 'POST',
            url: baseUrl + '/login',
            data: {
                login: name,
                password: pass
            }
        }).then(
            function(res) {
                localStorageService.set('user', res.data);
                vm.user=res.data;
                vm.notify();
                deferred.resolve(res.data);
            },
            function(fail) {
                console.log('Nope : ' + fail.data);
                deferred.reject('Une erreur a eu lieu lors de la requête.');
            });
         return deferred.promise;
     };

     function logout() {
         localStorageService.remove('user');
         vm.user=undefined;
         vm.notify();
     }
  }
})();
