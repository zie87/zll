Shortcuts for `function_ref`

We made some shortcuts in the `function_ref` implementation:

* direct call to the callables (no `invoke`), this could mess up the calls for binding
* no specialisation to `invocables` this could end up in ugly compiler errors
* only support for one argument (to much boilerplate)
* void is not proper supported (would need a specialisation)
