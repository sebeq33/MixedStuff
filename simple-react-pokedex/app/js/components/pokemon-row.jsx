import React, {Component, PropTypes} from 'react';
import classNames from 'classnames';

class PokemonRow extends Component {
    constructor(props) {
        super(props);
        this.name = this.props.name;
        this.number = this.props.number;
        this.selectPokemon = this.props.selectPokemon;
        this.callback = this.callback.bind(this);
    }

    callback() {
        this.selectPokemon(this.number);
    }

    render() {
        return (
            <tr>
                <td onClick={this.callback}>
                    <p className={classNames('notification', {'is-success': this.props.selectedPokemonNumber === this.number})}>
                        {this.number} {this.name}
                    </p>
                 </td>
            </tr>
        );
    }
}

PokemonRow.propTypes = {
    name: PropTypes.string,
    number: PropTypes.string,
    selectPokemon: PropTypes.func,
    selectedPokemonNumber: PropTypes.string
};

export default PokemonRow;
