(function() {
    angular
        .module('formationAngularJS')
        .service('ErrorService', ErrorService);

    /** @ngInject */
    function ErrorService(id) {
        this.vm=this;
        
    }
})();
