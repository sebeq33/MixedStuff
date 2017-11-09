import React from 'react';
import {expect} from 'chai';
import {shallow, mount, render} from 'enzyme';
import PokemonImage from '../../app/js/components/pokemon-image';

describe('PokemonImage suite', function () {
    it('should contains pokemon\'s name', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };
        var image = shallow(<PokemonImage name={bulbasaur.name} pokeStyle={bulbasaur.style}/>);
        expect(image.text()).to.equal('Bulbasaur');
    });

    it('should contains <span> html balise with style pokemon-icon', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };
        var image = shallow(<PokemonImage name={bulbasaur.name} pokeStyle={bulbasaur.style}/>);
        expect(image.html()).to.equal(`<span class="pokemon-icon n1">Bulbasaur</span>`);
    });
});