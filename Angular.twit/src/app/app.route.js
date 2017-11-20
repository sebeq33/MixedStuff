(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .config(routeConfig);

  function routeConfig($routeProvider) {
      $routeProvider
     .when('/home', {
        templateUrl: 'app/views/home/home.html',
        controller: 'MyController',
        controllerAs: 'home'
     })
     .when('/create', {
        templateUrl: 'app/views/create/create.html',
        controller: 'CreateController',
        controllerAs: 'create'
    })
    .when('/login', {
       templateUrl: 'app/views/login/login.html',
       controller: 'LoginController',
       controllerAs: 'login'
    })
    .when('/profile/:user', {
       templateUrl: 'app/views/profile/profile.html',
       controller: 'ProfileController',
       controllerAs: 'profile'
    })
    .when('/messages', {
       templateUrl: 'app/views/messages/messages.html',
       controller: 'MessagesController',
       controllerAs: 'messages'
    })
     .otherwise({
       redirectTo: '/login'
     });
  }
})();
