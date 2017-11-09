import React, {Component, PropTypes} from 'react';
import classNames from 'classnames';

class PokemonInformation extends Component {
    constructor(props) {
        super(props);
    }

    render() {
        const res = [];
        React.Children.forEach(this.props.children, (item, i) => {
            if (i !== 0)
            {
                const hrkey = i + 'hr';
                res.push(<hr key={hrkey}/>);
            }
            res.push(item);
        });
        return (
            <div className={classNames('box')}>{res}</div>
        );
    }
}

PokemonInformation.propTypes = {
    children: PropTypes.oneOfType([
        PropTypes.element,
        PropTypes.array
    ])
};

export default PokemonInformation;
