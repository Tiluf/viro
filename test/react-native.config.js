// react-native.config.js
module.exports = {
  dependencies: {
    'react-viro': {
      platforms: {
        android: null, // disable Android platform, other platforms will still autolink if provided
      },
    },
  },
};
