(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .controller('LoginController', LoginController);

  /** @ngInject */
  function LoginController(LoginService, $location) {
    var vm = this;

    vm.send = send;
    function send () {
        if (vm.name !== undefined && vm.pass !== undefined) {
            LoginService.login(vm.name, vm.pass)
            .then(function(res){
                vm.message='Success';
                console.log(vm.name);
                $location.url('profile/' + vm.name);},
             function(fail){
                console.log(fail);
                vm.message='Can\'t connect : ' + fail.toLowerCase();
            });
        } else {
            vm.message="Error : wrong data.\n Learn to type, motherfucker !!";
        }
    };
  }
})();
