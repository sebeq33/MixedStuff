import React from 'react';
import {expect} from 'chai';
import {shallow, mount, render} from 'enzyme';
import PokemonNotFound from '../../app/js/components/pokemon-not-found';

describe('PokemonNotFound suite', function () {

    it('should have a div', () => {
        var notFound = shallow(<PokemonNotFound />);

        expect(notFound.find('div')).to.have.length(1);
    });

    it('should have a img', () => {
        var notFound = shallow(<PokemonNotFound />);

        expect(notFound.find('img')).to.have.length(1);
    });

    it('should contains text', () => {
        var notFound = shallow(<PokemonNotFound />);

        expect(notFound.text()).to.contain('Nothing to see here !');
    });
});