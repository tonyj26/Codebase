import React from 'react';
import ReactDom from 'react-dom';
import './index.css';

function FancyBorder(props) {
  return (
    <div className={'FancyBorder FancyBorder-' + props.color}>
      {props.children}
    </div>
    );
}

function WelcomeDialog() {
  return (
    <Dialog 
      title="Welcome"
      message="Thank you for visiting our spacecraft!" />
    );
}

function Dialog(props) {
  return (
    <FancyBorder color="blue">
      <h1 className="Dialog-title">
        {props.title}
      </h1>
      <p> className="Dialog-message">
        {props.message}
      </p>
    </FancyBorder>
    );
}

