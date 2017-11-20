(function() {
  'use strict';

  angular
    .module('formationAngularJS')
    .controller('MessagesController', MessagesController);

  /** @ngInject */
  function MessagesController(MessageService) {
    var vm = this;
    vm.limit = 100;
    vm.currentMessage = '';
    vm.sendMessage = sendMessage;
    vm.getMessages = getMessages;
    vm.show = show;
    vm.getCarret = getCarret;

    function getMessages()
    {
        MessageService.getMessages().then(
            function(res) {
                vm.data = res.data;
                vm.data.forEach(function(item) {
                    item.response='';
                    item.showComments = false;
                    item.sendResponse = function() {
                           if (!item.response || item.response.length === 0) {
                                return;
                            }
                            MessageService.sendMessage(item.response, item._id).then(function() {
                                item.response = '';
                                MessageService.getComments(item._id).then(function(res) {
                                    item.comments=res.data;
                                });
                            });
                    };
                });
            },
            function(fail) {
                console.log('Nope : ' + fail.data);
            });
    }

    function sendMessage()
    {
        if (!vm.currentMessage || vm.currentMessage.length === 0)
        {
            return;
        }
        MessageService.sendMessage(vm.currentMessage).then(function() {
            vm.currentMessage = '';
            vm.getMessages();
        });
    }

    function show(message)
    {
        message.showComments = !message.showComments
    }

    function getCarret(message) {
        return message.showComments ? 'fa fa-caret-up' : 'fa fa-caret-down';
    }
    getMessages();
  }
})();
