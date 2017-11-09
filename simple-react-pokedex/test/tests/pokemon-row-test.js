import React from 'react';
import {expect} from 'chai';
import {shallow, mount, render} from 'enzyme';
import PokemonRow from '../../app/js/components/pokemon-row';

describe('PokemonRow suite', function () {
    it('should change the selected pokemon', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };

        var selectedPokemon = '#002';

        let selectPokemon = (pokemonNumber) => {
            selectedPokemon = pokemonNumber;
        };

        var row = shallow(
            <PokemonRow name={bulbasaur.name} key={bulbasaur.number} number={bulbasaur.number}
                        selectedPokemonNumber={selectedPokemon} selectPokemon={selectPokemon}/>
        );

        row.find('td').simulate('click');

        expect(selectedPokemon).to.equal('#001');
    });

    it('should render the cell', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };

        var selectedPokemon = '#002';

        let selectPokemon = (pokemonNumber) => {
            selectedPokemon = pokemonNumber;
        };

        var row = shallow(
            <PokemonRow name={bulbasaur.name} key={bulbasaur.number} number={bulbasaur.number}
                        selectedPokemonNumber={selectedPokemon} selectPokemon={selectPokemon}/>
        );

        expect(row.html()).to.equal(`<tr><td><p class="notification">#001 Bulbasaur</p></td></tr>`);
    });

    it('should render a p.notification', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };

        var selectedPokemon = '#002';

        let selectPokemon = (pokemonNumber) => {
            selectedPokemon = pokemonNumber;
        };

        var row = shallow(
            <PokemonRow name={bulbasaur.name} key={bulbasaur.number} number={bulbasaur.number}
                        selectedPokemonNumber={selectedPokemon} selectPokemon={selectPokemon}/>
        );

        expect(row.find('p.notification')).to.have.length(1);
    });

    it('should have class is-success when selected pokemon is rendered pokemon', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };

        var selectedPokemon = '#001';

        let selectPokemon = (pokemonNumber) => {
            selectedPokemon = pokemonNumber;
        };

        var row = shallow(
            <PokemonRow name={bulbasaur.name} key={bulbasaur.number} number={bulbasaur.number}
                        selectedPokemonNumber={selectedPokemon} selectPokemon={selectPokemon}/>
        );

        expect(row.find('p.is-success')).to.have.length(1);
    });
});