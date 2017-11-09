import React, {Component, PropTypes} from 'react';
import PokemonRow from './pokemon-row';
import classNames from 'classnames';

class PokemonTable extends Component {
    constructor(props) {
        super(props);
        this.pokemons = this.props.pokemons;
        this.selectPokemon = this.props.selectPokemon;
    }

    render() {
        const rows = [];
        this.pokemons.forEach(item => {
            rows.push(<PokemonRow
                name={item.name}
                number={item.number}
                selectPokemon={this.selectPokemon}
                selectedPokemonNumber={this.props.selectedPokemonNumber}
                key={item.number}/>);
        });
        return (
            <table className={classNames('table', 'is-bordered')}>
                <tbody>
                    {rows}
                </tbody>
            </table>
        );
    }
}

PokemonTable.propTypes = {
    pokemons: PropTypes.array,
    selectPokemon: PropTypes.func,
    selectedPokemonNumber: PropTypes.string
};

export default PokemonTable;
