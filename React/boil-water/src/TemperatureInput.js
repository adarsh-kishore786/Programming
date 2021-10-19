import React from "react"

const scaleNames = {
    c: "Celsius",
    f: "Fahrenheit"
};

class TemperatureInput extends React.Component {
    constructor(props) {
        super(props);
        this.handleChange = this.handleChange.bind(this);
        this.state = {temperature: ''};
    }

    handleChange(e) {
        this.props.onTemperatureChange(e.target.value);
    }

    render() {
        const temp = this.props.temperature;
        const scale = this.props.scale;
        return(
            <div>
                <legend>Enter temperature in {scaleNames[scale]}:</legend>
                <input value={temp}
                       onChange={this.handleChange} />
            </div>
        );
    }
};

export default TemperatureInput
