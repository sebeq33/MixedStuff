import 'bulma';
import ReactDom from 'react-dom';
import React from 'react';
import Pokedex from './pokedex';
import pokemons from '../root/pokedex.json';

ReactDom.render(
    <Pokedex pokemons={pokemons}/>,
    document.getElementById('app')
);