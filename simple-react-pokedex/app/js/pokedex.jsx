import React, {Component, PropTypes} from 'react';
import PokemonInformation from './components/pokemon-information';
import PokemonTable from './components/pokemon-table';
import PokemonImage from './components/pokemon-image';
import PokemonDescription from './components/pokemon-description';

class Pokedex extends Component {
    constructor(props) {
        super(props);
        this.pokemons = props.pokemons;
        this.state = {
            selectedPokemonNumber : props.pokemons[0].number
        };
        this.selectPokemon = this.selectPokemon.bind(this);
    }

    selectPokemon(pokeNumber)
    {
        this.setState({selectedPokemonNumber: pokeNumber});
    }

    render() {
        const selectedPokemon = this.pokemons.find(pokemon => pokemon.number === this.state.selectedPokemonNumber);

        return (
            <div className="columns">
                <div className="column is-one-quarter">
                    <PokemonTable
                        pokemons={this.pokemons}
                        selectedPokemonNumber={selectedPokemon.number}
                        selectPokemon={this.selectPokemon}/>
                </div>
                <div className="column">
                    <PokemonInformation>
                        <PokemonImage name={selectedPokemon.name} pokeStyle={selectedPokemon.style}/>
                        <PokemonDescription pokemon={selectedPokemon}/>
                    </PokemonInformation>
                </div>
            </div>
        );
    }
}

Pokedex.propTypes = {
    pokemons: PropTypes.array.isRequired
};

export default Pokedex;
