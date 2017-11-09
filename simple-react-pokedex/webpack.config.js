const TransferWebpackPlugin = require('transfer-webpack-plugin');
const path = require('path');
const webpack = require('webpack');

const NODE_ENV = process.env.NODE_ENV;

let resolve = {
    alias: {
        bulma: 'bulma/css/bulma.css'
    },
    extensions: ['.js', '.jsx']
};

const plugins = [
    new TransferWebpackPlugin([{from: 'app/root'}]),
    new webpack.optimize.CommonsChunkPlugin({
        name: 'vendor',
        filename: 'vendor.js',
        minChunks: Infinity
    })
];

const rules = [
    {
        test: /\.css$/,
        use: [
            {loader :'style-loader'},
            {loader :'css-loader'}
        ]
    },
    {
        test: /\.jsx?$/,
        enforce: "pre",
        exclude: /node_modules/,
        use: [{
            loader :'eslint-loader',
            options: {
                failOnWarning: false,
                failOnError: true
            }
        }]
    },
    {
        test: /\.jsx?$/,
        exclude: /node_modules/,
        use: [{
            loader: 'babel-loader',
            options: {
                presets: ['es2015', 'react']
            }
        }]
    }
];

if (NODE_ENV === 'production') {
    plugins.push(new webpack.DefinePlugin({
        'process.env': {
            NODE_ENV: JSON.stringify(NODE_ENV) // Some library like React use this value in order to exclude test helpers
        }
    }));

    Object.assign(resolve.alias, {
        react: 'react/dist/react.min.js',
        'react-dom': 'react-dom/dist/react-dom.min.js'
    });

    // We must add this loader before babel loader because this loader is only for our source.
    rules.unshift({
        test: /\.jsx?$/,
        exclude: /node_modules/,
        use: ['uglify-loader']
    });
}

const config = {
    entry: {
        app: ['./app/js/main.jsx'],
        vendor: ['react', 'react-dom']
    },
    resolve: resolve,
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'bundle.js'
    },
    module: {
        rules
    },
    plugins: plugins
};

if (NODE_ENV !== 'production') {
    config.devtool = "source-map";
}

module.exports = config;
