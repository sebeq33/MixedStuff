import React from 'react';
import {expect} from 'chai';
import {shallow, mount, render} from 'enzyme';
import Pokedex from '../../app/js/pokedex';

describe('Pokedex suite', function () {
    it('should own at least a PokemonTable', () => {
        let pokemons = [{
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        }];

        var pokedex = shallow(
            <Pokedex pokemons={pokemons}/>
        );

        expect(pokedex.find('PokemonTable')).to.have.length(1);
    });

    it('should own at least a PokemonInformation', () => {
        let pokemons = [{
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        }];

        var pokedex = shallow(
            <Pokedex pokemons={pokemons}/>
        );

        expect(pokedex.find('PokemonInformation')).to.have.length(1);
    });

    it('should own at least a PokemonImage', () => {
        let pokemons = [{
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        }];

        var pokedex = shallow(
            <Pokedex pokemons={pokemons}/>
        );

        expect(pokedex.find('PokemonImage')).to.have.length(1);
    });

    it('should own at least a PokemonDescription', () => {
        let pokemons = [{
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        }];

        var pokedex = shallow(
            <Pokedex pokemons={pokemons}/>
        );

        expect(pokedex.find('PokemonDescription')).to.have.length(1);
    });

    it('should change the selected pokermon', () => {
        let pokemons = [
            {
                style: 'n2',
                number: '#002',
                name: 'Ivysaur',
                type: 'Grass',
                secondType: 'Poison'
            },
            {
                style: 'n1',
                number: '#001',
                name: 'Bulbasaur',
                type: 'Grass',
                secondType: 'Poison'
            }
        ];

        var pokedex = mount(<Pokedex pokemons={pokemons}/>);

        expect(pokedex.state().selectedPokemonNumber).to.equal('#002');

        pokedex.find('p.notification').last().simulate('click');

        expect(pokedex.state().selectedPokemonNumber).to.equal('#001');
    });

    it('should render the pokedex', () => {
        let pokemons = [{
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        }];

        var pokedex = shallow(
            <Pokedex pokemons={pokemons}/>
        );

        expect(pokedex.html()).to.equal(`<div class="columns"><div class="column is-one-quarter"><table class="table is-bordered"><tbody><tr><td><p class="notification is-success">#001 Bulbasaur</p></td></tr></tbody></table></div><div class="column"><div class="box"><span class="pokemon-icon n1">Bulbasaur</span><hr/><p>Bulbasaur is a Pokemon of type Grass and Poison. It has the number #001</p></div></div></div>`);
    });
});