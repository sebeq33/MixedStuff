(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .service('CreateService', CreateService);

  /** @ngInject */
  function CreateService($http, baseUrl) {
    this.create = create;

    function create(name, email, pass, desc){
      return $http({
        method: 'POST',
        url: baseUrl + '/createUser',
        data: {
            login: name,
            mail: email,
            password: pass,
            desc: desc
        }
      });
    }
  }
})();
