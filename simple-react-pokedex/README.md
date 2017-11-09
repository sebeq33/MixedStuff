# Hand on React - Pokédex

## Requirements
Example4 done. 

## Goals
- Understand the difference between a reusable component (here `PokemonInformation`) and a "hierarchical component" (`PokemonTable`).
- See how we can inverse the data flows (here between the row and the pokedex.)
- Play a bit with CSS in react (there are many other ways to deal with it... my favorite is CSS Modules).

## Expected results
A simple pokédex.
![Pokedex splited in React component](https://github.com/e-biz/handson-react/blob/master/example5-pok%C3%A9dex/pokedexReactComponent.jpg)

## Documentation
- [CheatSheet](http://reactcheatsheet.com/)
- [CSS Modules](https://github.com/gajus/react-css-modules)
- [Reusable Components](https://facebook.github.io/react/docs/reusable-components.html)
- [Thinking in react](https://facebook.github.io/react/docs/thinking-in-react.html)
- [React Patterns](https://github.com/krasimir/react-in-patterns/tree/master/patterns/composition)

## Instructions
Create a Pokédex with all the previous things learned.

Have a look at the model: `app/root/pokedex.json`.

1. Fill the `PokemonRow` component:
    1. PokemonRow receive 3 properties to add in the constructor: the `name` of the pokemon to display, the `number` of the pokemon to display and callback (`selectPokemon`) to call when click on the desire pokemon.
    2. Create a method that will call this callback and bind it to this (no auto binding in ES6 so we have to do it manually).
    3. Create the render method with row (`<tr>`) and a unique cell (`<td>`) when we click on the cell (`onClick`) it call the previously create method.
    4. In the cell create a paragraph (`<p>`) that contains the number and the name of the pokemon.
    5. Style the paragraph (`className`) with a bulma class `notification`. Also with `is-success` if the PokemonRow is the selected one (use classNames: `classNames({is-success: myCondition})`).
    6. Test your component with `npm run test:row`.

2. Fill the `PokemonImage` component:
    1. Create a span that contains the pokemon's name.
    2. Style it (`className`) with `pokemon-icon` and with the style of the object pokemon. Use `classNames`.
    3. Test your component with `npm run test:image`.
    
3. Fill the `PokemonDescription` component:
    1. Create a paragraph with the following text (example for Bulbasaur.) 
    2. `Bulbasaur is a Pokemon of type Grass and Poison. It has the number #001`.
    3. Test your component with `npm run test:description`.
    
4. Fill the `PokemonTable` component:
    1. PokemonTable receive two properties to add in the constructor. The callback that the row will call to update the selected component (name it `selectPokemon`) and the list of pokemon (let's say pokemons).
    2. Map the list of pokemons into a list of `PokemonRow` (dont forgot the key).
    3. Display this row in a table (`table>tbody`).
    4. Style the table with `table` and `is-bordered`.
    5. Test your component with `npm run test:table`

5. Fill the `PokemonInformation` component:
    1. Render a list of children `this.props.children`.
    2. Map the list of children in order to add a `<hr />` between each child. (Don't forgot the key !).
    3. Test your component with `npm run test:information`.
    
6. Fill the Pokedex component:
    1. The constructor of Pokedex receive pokemons as parameter. It init its own state (`selectedPokemonNumber`) with the number of the first pokemon and bind with this its own method `selectPokemon`.
    2. The method `selectPokemon` takes a pokemonNumber as parameter and put it in its state (`this.setState({key: value})`).
    3. Find the selected pokemon (using filter and first of lodash) in the render method.
    4. Create a PokemonTable JSX with the pokemons, the selected pokemon and the method `selectPokemon` (our callback).
    5. Create a `PokemonInformation` with children `PokemonImage` and `PokemonDescription` in JSX.
    6. `PokemonImage` has two parameter: the name and the style of the selected pokemon.
    7. `PokemonDescription` has one parameter: the selected pokemon.
    8. Test your component with `npm run test:pokedex`
    
## Bonus
Transform the PokemonRow, PokemonImage and PokemonDescription into stateless functions.
