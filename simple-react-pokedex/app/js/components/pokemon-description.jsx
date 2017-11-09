import React, {Component, PropTypes} from 'react';

class PokemonDescription extends Component {
    constructor(props) {
        super(props);
    }

    render() {

        return (
            <p>
                {this.props.pokemon.name} is a Pokemon of type {this.props.pokemon.type}
                {this.props.pokemon.secondType && (' and ' + this.props.pokemon.secondType)}.
                It has the number {this.props.pokemon.number}
            </p>
        );
    }
}

PokemonDescription.propTypes = {
    pokemon: PropTypes.object
};

export default PokemonDescription;
