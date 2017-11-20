(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .controller('CreateController', CreateController);

  /** @ngInject */
  function CreateController(CreateService, $location) {
    var vm = this;

    vm.send = send;
    function send () {
        var success = true;

        if (vm.name === undefined || vm.email === undefined || 
            vm.pass === undefined || vm.confirm === undefined)
        {
            success = false;
        }
        else {
            if (!vm.email.match(/^[^@]+@[^.]+\.[^.]+$/))
            {
                success = false;
            }

            if (vm.pass !== vm.confirm) {
                success = false;
            }

            if (vm.name.length > 49 || vm.email.length > 49 || 
                vm.pass.length > 49 || vm.desc.length > 249)
            {
                success = false;
            }
        }

        if (success) {
            CreateService.create(vm.name, vm.email, vm.pass, vm.desc)
            .then(function(msg){
                vm.message='Success';
                $location.url('login');},
             function(msg){
                console.log(msg.levelLabel);
                vm.message='Internal server error';
            });
        } else {
            vm.message="Error : wrong data.\n Learn to type, motherfucker !!";
        }
    };
  }
})();
