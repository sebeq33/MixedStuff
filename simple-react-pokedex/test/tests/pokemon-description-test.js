import React from 'react';
import {expect} from 'chai';
import {shallow, mount, render} from 'enzyme';
import PokemonDescription from '../../app/js/components/pokemon-description';

describe('PokemonDescription suite', function () {
    it('should contains description text', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };
        var description = shallow(<PokemonDescription pokemon={bulbasaur}/>);
        expect(description.text()).to.equal('Bulbasaur is a Pokemon of type Grass and Poison. It has the number #001');
    });

    it('should contains <p> html balise', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };
        var description = shallow(<PokemonDescription pokemon={bulbasaur}/>);
        expect(description.find('p')).to.have.length(1);
    });
});