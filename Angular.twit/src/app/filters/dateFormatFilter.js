(function() {
    'use strict'

    angular
        .module('formationAngularJS')
        .filter('dateFormat', DateFormat)
        .filter('dateFromNow', DateFromNow)

    /** @ngInject */
    function DateFormat(moment) {
        return function(str, format) {
            return moment(str).format(format);
        };
    }

    /** @ngInject */
    function DateFromNow(moment){
        return function(str){
            return moment(str).fromNow();
        }
    }
})();
