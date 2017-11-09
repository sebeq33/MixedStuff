import React from 'react';
import {expect} from 'chai';
import {shallow, mount, render} from 'enzyme';
import PokemonImage from '../../app/js/components/pokemon-image';
import PokemonInformation from '../../app/js/components/pokemon-information';
import PokemonDescription from '../../app/js/components/pokemon-description';

describe('PokemonInformation suite', function () {
    it('should render all component', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };
        var information = shallow(
            <PokemonInformation>
                <PokemonImage name={bulbasaur.name} pokeStyle={bulbasaur.style}/>
                <PokemonDescription pokemon={bulbasaur}/>
            </PokemonInformation>);
        expect(information.props().children).to.have.length(3);
    });

    it('should wrap our children in a div.box', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };
        var information = shallow(
            <PokemonInformation>
                <PokemonImage name={bulbasaur.name} pokeStyle={bulbasaur.style}/>
                <PokemonDescription pokemon={bulbasaur}/>
            </PokemonInformation>);
        expect(information.find('div.box')).to.have.length(1);
    });

    it('should separate children with hr', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };
        var information = shallow(
            <PokemonInformation>
                <PokemonImage name={bulbasaur.name} pokeStyle={bulbasaur.style}/>
                <PokemonDescription pokemon={bulbasaur}/>
            </PokemonInformation>);
        expect(information.find('hr')).to.have.length(1);
    });

    it('should render for bulbasaur', () => {
        let bulbasaur = {
            style: 'n1',
            number: '#001',
            name: 'Bulbasaur',
            type: 'Grass',
            secondType: 'Poison'
        };
        var information = shallow(
            <PokemonInformation>
                <PokemonImage name={bulbasaur.name} pokeStyle={bulbasaur.style}/>
                <PokemonDescription pokemon={bulbasaur}/>
            </PokemonInformation>);
        expect(information.html()).to.equal(`<div class="box"><span class="pokemon-icon n1">Bulbasaur</span><hr/><p>Bulbasaur is a Pokemon of type Grass and Poison. It has the number #001</p></div>`);
    });
});