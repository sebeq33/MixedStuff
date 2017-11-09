import React from 'react';
import {expect} from 'chai';
import {shallow, mount, render} from 'enzyme';
import PokemonTable from '../../app/js/components/pokemon-table';
import pokemons from '../../app/root/pokedex.json'

describe('PokemonTable suite', function () {
    it('should render pokemons', () => {
        var selectedPokemon = '#001';

        let selectPokemon = (pokemonNumber) => {
            selectedPokemon = pokemonNumber;
        };

        var table = shallow(
            <PokemonTable pokemons={pokemons} selectedPokemonNumber={selectedPokemon}
                          selectPokemon={selectPokemon}/>
        );

        expect(table.find('PokemonRow')).to.have.length(151);
    });

    it('should have the element table.table', () => {
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

        var table = shallow(
            <PokemonTable pokemons={[bulbasaur]} selectedPokemonNumber={selectedPokemon}
                          selectPokemon={selectPokemon}/>
        );

        expect(table.find('table.table')).to.have.length(1);
    });

    it('should have the element table.is-bordered', () => {
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

        var table = shallow(
            <PokemonTable pokemons={[bulbasaur]} selectedPokemonNumber={selectedPokemon}
                          selectPokemon={selectPokemon}/>
        );

        expect(table.find('table.is-bordered')).to.have.length(1);
    });


    it('should render the table html', () => {
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

        var table = shallow(
            <PokemonTable pokemons={[bulbasaur]} selectedPokemonNumber={selectedPokemon}
                          selectPokemon={selectPokemon}/>
        );

        expect(table.html()).to.equal(`<table class="table is-bordered"><tbody><tr><td><p class="notification">#001 Bulbasaur</p></td></tr></tbody></table>`);
    });
});