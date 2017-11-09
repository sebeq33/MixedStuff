import React, {Component, PropTypes} from 'react';
import classNames from 'classnames';

class PokemonImage extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        return (
            <span className={classNames('pokemon-icon', this.props.pokeStyle)}>{this.props.name}</span>
        );
    }
}

PokemonImage.propTypes = {
    pokeStyle: PropTypes.string,
    name: PropTypes.string
};

export default PokemonImage;
