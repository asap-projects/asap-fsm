# Changelog

All notable changes to this project will be documented in this file. See [standard-version](https://github.com/conventional-changelog/standard-version) for commit guidelines.

## [1.0.6](http://github.com/abdes/asap/compare/v1.0.5...v1.0.6) (2022-03-15)

chore: enable ccache in cmake presets

## [1.0.5](http://github.com/abdes/asap/compare/v1.0.4...v1.0.5) (2022-03-15)

- refactor build to use CPM for cmake dependencies and speedup build with ccache.

### Bug Fixes

- method IsIn() should be const ([e022a57](http://github.com/abdes/asap/commit/e022a57cb99e0c5fb26b288730d802800e7fe9bb))
- only add sanitizers if building tests ([76c1ccf](http://github.com/abdes/asap/commit/76c1ccf3f2651b40c19a2f2c68aa242eb7255331))
- only install docs if directory exists ([82fe620](http://github.com/abdes/asap/commit/82fe620e6dcd2a8e81f640dcd893b7c67b2cc2ae))

## [1.0.4](http://github.com/abdes/asap/compare/v1.0.3...v1.0.4) (2022-03-06)

### Bug Fixes

- refresh immediately as we only have one sub-module ([d0f98ef](http://github.com/abdes/asap/commit/d0f98ef7aea440278d079474a1de5e0cb2d8ea93))

## [1.0.3](http://github.com/abdes/asap/compare/v1.0.2...v1.0.3) (2022-03-06)

### Bug Fixes

- wrong project title used in html doc ([ad83c59](http://github.com/abdes/asap/commit/ad83c59351e8d2b1ab762527757130eab9d83f8d))

## [1.0.2](http://github.com/abdes/asap/compare/v1.0.1...v1.0.2) (2022-03-06)

### Bug Fixes

- define asap_top_level_install as empty when project install should be skipped ([75a769f](http://github.com/abdes/asap/commit/75a769fedcce026fec7d16728aafa2133ec59152))
- wrong links for project documentation ([e3b4f92](http://github.com/abdes/asap/commit/e3b4f92d4abf9067102317638b8b8976002db6ba))

## [1.0.1](http://github.com/abdes/asap/compare/v1.0.0...v1.0.1) (2022-03-06)

### Bug Fixes

- always use top level build dir for output ([1b01db2](http://github.com/abdes/asap/commit/1b01db2402bc52944646bcde3cf525315a4e0e1b))
- doxygen and sphinx target conflict with modules ([02375ff](http://github.com/abdes/asap/commit/02375ff4a33e34a8e0cb9307ef4eb6de3271e945))
- generate doc only if project is master ([82190fa](http://github.com/abdes/asap/commit/82190fa6562f5e51dbbab660bcab8dc265e99a0b))
- make doxygen targets sub-project friendly ([546fe73](http://github.com/abdes/asap/commit/546fe73ded53721dddbac311e9db41e4146b8ad2))
- make gtest work again ([3ce658c](http://github.com/abdes/asap/commit/3ce658c5f1eb216a3286717e7f80827b96ff3b49))
- make sphinx targets sub-project friendly ([024cc77](http://github.com/abdes/asap/commit/024cc77d17ed134ed5f3f4eea32226b07b05aad6))
- only add clang-format/tidy targets if master project ([060f082](http://github.com/abdes/asap/commit/060f082714e039eb4c2c2e198b5caed74690e8af))
- only add sanitizers if building tests ([7625caa](http://github.com/abdes/asap/commit/7625caac88429996e0962b95f3a26d536e6cb49e))
- only install files if requested to install ([9caaf9b](http://github.com/abdes/asap/commit/9caaf9b47e138be3f9845d6d58ebc21ff8dfa83b))
- reorganize third_party modules for use of FetchContent ([cc65bc2](http://github.com/abdes/asap/commit/cc65bc2219dbe38197107bae71252444994e118c))
- use correct path for the master docs ([3e01ccd](http://github.com/abdes/asap/commit/3e01ccd05d2daa2aade55dddd70c1c43f6d2d3e1))
- use correct targets for doc builds ([fae6b2d](http://github.com/abdes/asap/commit/fae6b2d002900e7bbdf273a9e99ba700d93cfae0))
- use correct targets for doc builds ([559558e](http://github.com/abdes/asap/commit/559558e8eac3043eef19986cc2ae6d6dfd937be8))
- use correct url for `common` inter-sphinx ([8ed6100](http://github.com/abdes/asap/commit/8ed6100f818f7fe8e6af2a118c3c9f4be983aa74))
- use correct url for `common` sphinx docs ([cb77257](http://github.com/abdes/asap/commit/cb7725706540c28f6847472f2524285a1a994307))
- use correct url for logo image ([96d1e01](http://github.com/abdes/asap/commit/96d1e01d971bd2f33faaebfc060082023f3a5209))
- use correct url for master index page ([a56c327](http://github.com/abdes/asap/commit/a56c327ff3d7ab14d7a499fc4997279efd2647fe))
- use lower case META_PROJECT_ID ([311e433](http://github.com/abdes/asap/commit/311e433e8698ff6385c2cda256bff83982596ed0))
- wrong variable used for target name ([829f351](http://github.com/abdes/asap/commit/829f351d22b384ddc060ae2df47ff9e801089dd2))

## [1.0.0](http://github.com/abdes/asap/compare/v4.0.2...v1.0.0) (2022-02-17)

### Features

- initial version ([0b89372](http://github.com/abdes/asap/commit/0b893726ab41f7454d5fd1618d0be8f6a92cca43))

  The `fsm` module provides a template-based framework for implementing
  finite state machines in C++. States, their transitions and event
  handlers are statically typed for maximum compile-time enforcement
  of the valid transitions.
