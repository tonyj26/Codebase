import React, { Component } from 'react';

class Stopwatch(props) {
  constructor(props) {
    super(props);
    this.state = {isOn: false};

    this.handleStartClick = this.handleStartClick.bind(this);
  }

  handleStartClick() {
    this.({setState})
  }
  return <div>
    <h1>0:00</h1>
    <button type="button" onClick={this.handleStartClick}>start</button>
  </div>;
}
class App extends Component {
  render() {
    return (
      <div className="App">
        <Stopwatch />
      </div>
    );
  }
}

export default App;
