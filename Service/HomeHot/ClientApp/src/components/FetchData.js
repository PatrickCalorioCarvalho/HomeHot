import React, { Component } from 'react';

export class FetchData extends Component {
  displayName = FetchData.name

  constructor(props) {
    super(props);
    this.state = { leituras: [], loading: true };

    fetch('api/Sensors')
      .then(response => response.json())
      .then(data => {
        this.setState({ leituras: data, loading: false });
      });
  }

  static renderLeiturasTable(leituras) {
    return (
      <table className='table'>
        <thead>
          <tr>
            <th>Nome</th>
            <th>Umidade</th>
            <th>Temperatura</th>
            <th>Data</th>
          </tr>
        </thead>
        <tbody>
          {leituras.map(forecast =>
              <tr key={forecast.idSensor}>
                  <td>{forecast.nome}</td>
                  <td>{forecast.umidade}</td>
                  <td>{forecast.temperatura}</td>
                  <td>{forecast.data}</td>
            </tr>
          )}
        </tbody>
      </table>
    );
  }

  render() {
    let contents = this.state.loading
      ? <p><em>Carregando...</em></p>
        : FetchData.renderLeiturasTable(this.state.leituras);

    return (
      <div>
        <h1>Historico de Leitura</h1>
        {contents}
      </div>
    );
  }
}
