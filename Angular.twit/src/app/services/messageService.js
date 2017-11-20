(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .service('MessageService', MessageService);

  /** @ngInject */
  function MessageService($q, $http, localStorageService, baseUrl) {
    this.getMessages = getMessages;
    this.sendMessage = sendMessage;
    this.getComments = getComments;

    function getMessages()
    {
        return $http({
          method: 'GET',
          url: baseUrl + '/getMessages'
        });
    }

    function getComments(id) {
        return $http({
          method: 'GET',
          url: baseUrl + '/getComments/' + id
        });
    }

    function sendMessage(msg, i) {
        var deferred = $q.defer();
        var user = localStorageService.get('user');

        if (!user) {
          deferred.reject('please login');
        }
        else {
            $http({
                method: 'POST',
                url: baseUrl + '/sendMessage' + (i ? '/' + i : ''),
                data: {
                    mail: user.mail,
                    msg: msg,
                    token: user.token,
                    userName: user.login
                }
            }).then(
                function(res) {
                    deferred.resolve(res);
                },
                function(fail) {
                    console.log('Nope : ' + fail.data);
                    deferred.reject('Une erreur a eu lieu lors de la requête.');
                });
        }
        return deferred.promise;
    };
  }
})();
